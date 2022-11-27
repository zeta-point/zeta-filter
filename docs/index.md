# What people still don’t understand about rotations? Pssst… and probability

The reason why I wrote this is so that this idea won’t get lost. I was mainly disappointed with the people whom this work was presented. Well because they didn’t care at all to even read it. Don’t get me wrong they had experience and were specialized in these topics and yet apart from a single person or two of them if not mistaken - they simply didn’t give a … you know what.
If you have no interest in engineering, signal processing, Kalman filtering - Sir, Madam please… save the world by not reading this. I warned you.

![](memes/morpheus.jpg)

I think it all began from the advancement and boom of MEMS devices. Meanwhile, continuous growth of microprocessors computational power and its cost reduction were the main factors responsible for amateur and then commercial drones market expansion. Hundreds of thousands of robotic freaks and geeks around the world began the race to develop and manufacture better and better flight/drive/swim whatever automated controller or just in short autopilot or however fancy name they choose to highlight how great, powerful and advanced their product is. Marketing loves it. It hasn't even stopped there. People need to know what is insight even if they don’t really understand what is inside. So, what’s there? Usually they write about used components and their performance and applied algorithms/filters their product uses. The heart of these is Attitude and Heading Reference System ( AHSR ) which is for 99.9% of these products the most sophisticated thing inside - in terms of applied math.

Now let me tell you something. I swear, there are more variations of AHRS algorithms out there than the actual number of products on the market. Complementary, Madgwick, Mahony, QUEST, Kalman Filter, Extended Kalman Filter, Error-state Multiplicative Extended Kalman Filter, Adaptive-Step Gradient Descent Kalman Filter. Should I continue on this? Why don't you say stop? It’s getting even worse…

![](memes/filters.png)

Have you heard about Euler angles? No? Then maybe about the rotation matrix or so called Direct Cosine Matrix …or axis-angle tuple? Of course you must have heard about them! Tait-Bryans angles? I bet the first thought that comes to your mind when you get up in the morning is about rotation quaternions.

The ugly “thing”
When I first heard about “quaternion renormalization” it was like… you guys must be kidding me. No seriously, each time you do this a kitten dies. Well, you say “quaternions need to have a unit norm for proper operation” - I say no, do not do this. You know, this renormalization thing is maybe not as bad as the operation you are making and is causing this “problem”.

Now I know it for sure. Do you think PhD’s are smart people? I bet on this there are even below 10% of professors in universities that drive innovations. Rest, well they do just their copy paste job even if it is meant to be a really serious scientific paper. Maybe not word by word but the logical correctness of the laid foundations are more or less the same. They just need to keep doing papers for their job, you know. There are some minimum limits on this. Going back to the topic, how do you think otherwise people would put the statement like “you need a unit quaternion for rotation representation / proper operation”. Have you ever heard about complex numbers? When multiplied arguments add, magnitudes scale. Where do you have a single word saying only unit complex numbers rotates - roughly speaking ?

![](memes/rotates.jpg)

Maybe renormalization is just a problem of quaternions? Guess what? Other structures are also depegging. Would you mind explaining that? Sure, it’s because of the accumulation of numerical errors in discrete devices. You know discrete integration, or rather summation, drifts, things like that and so on… Bravo. Would you mind explain to me also what are you guys doing in update step of your filters. Is this not a real reason why you renormalize state ? I get it, nobody cares, maybe hardly anyone sees this problem and if it works then what is the problem?

Look around! What I’m trying to say to you is that rotation in terms of complex numbers is done by multiplication.  Yet the majority of filters ( let's be fair - not all ) is trying to apply additive, yes additive, not multiplicative correction. And you better have a good explanation for that! Well, the explanation looks more or less like this: even though we can have a nonlinear update of the state, that's not the case for the error propagation equation. So it boils down to the applied statistical model itself which is in most of these filters assumed to be normal and would take advantage of Bayessian probability. Then all the best you can do is to calculate Jacobians from state and output matrices because eventually things need to be linearized.

Let’s bust this myth about renormalization once and forever - no more quaternions abuse. As you may have already seen, this is not meant to be another scientific paper. No continuous kinematic equations whatsoever - I’m already sick of writing all of this copy-paste bullshit. Take it as granted - a practical guide for implementation. I just want to show something quite interesting and that’s it. There will be just one proof - it works.

Hold on a little bit, geeky fellow because what you will see now is not rocket science, although it needs time to fully digest the implications and how elegant the idea is - meaning very, very, very simple. So simple I’m still wondering why anyone else has even tried this before. There must be someone, somewhere…maybe not. I won’t dive straight into quaternions - complex numbers are just fine to not cause a headache for the majority of readers. 

What I claim is this: error propagation equations and model/state are the same. Same meaning, this is the same single equation.

So there are many variations of KF when it comes to attitude estimation but at the end they all have the same foundations - gaussian noise, bayesian rules for posteriori distribution. For random variable X that obeys normal distribution, people write:


and its PDF looks like this


First let’s not be mentally constrained about this specific fact that variance have to be positive and real


Oh no, what just happened! But the integral must be 1! What about complex probability and so on? The world won’t be the same place anymore. To be honest I don’t care about this. There was a time when negative numbers were not numbers. Could you freaky believe that?

What is so special about complex variance? Well, as any complex number it has its argument and magnitude - or should I say norm to be politically correct? No, I should not. Rather than saying variance is complex I like to say it just has its direction.

Also, to avoid confusion and for the sake of simplicity let's just stick to the notation people already got used to. So, let's redefine complex variance or actually a complex “precision”. Yes, they call variance reciprocal a precision.


Now the state equation/model or however called - discrete of course.



I mean… I’m sorry. This is the error propagation equation for a priori step. Just kidding, this is actually the state. Do you understand? I dare to estimate the error in the state equation. Now one of these professors should come to announce you did not pass to the next term. How can I do this? 

![](memes/greta.png)

Well, fairly simple, All sigmas are real and also alpha and beta are real. Then, there is no way alpha and beta affects magnitude and same story for sigma on the argument. There are detached, independent dimensions - just orthogonal coordinates, you know… Yes, beta is equivalent to a control vector and also guess what? I’m not estimating errors of full state just this tiny little alpha guy. Finally, if you remember or not I can add these sigmas together because of the… you know… convolution product or something. Yes, of course they are independent variables - they always do in such papers! Now, move on to the update step.

What this posteriori distribution will tell you? It’s nothing new than being done in KF right? Or you actually haven’t done your homework and are so curious to check it? Will you also just do copy pasting?



Nothing new right?



Let’s jump right now to the complex plane.


Holy mother of all the Kalman Filters papers! Let me tell you this is the most relieving moment. If you still don’t see it, let me explain. Update step is just about adding numbers of the complex plane. Brilliant in its simplicity. This is what complex variance means. Don’t even dare to renormalize it! Or you will be accused of all of these kittens' premature deaths. I know you do this at least one hundred times per second!

![](memes/kitten.jpg)

Do you think it’s the same as in one of yours KF ? Your renormalization crap does not even allow for proper settlement of your state in some circumstances. And what if I told you there is such a measurement/observation that can actually reduce your “certainty” about the given attitude estimate? How do you think your KF will deal with that? Oh, I get it. In the paper there is a note “assuming small angles”. That’s a good and clever excuse but you know what? There is no such a problem here! Full nonlinearity, hashtag born to be wild! 

Let’s summarize what I call a zeta filter - with respect to the EKF attitude estimation ( quaternion based or whatever renormalization you do )

compact, lightweight
all quaternion / complex numbers space used and when I say all space I mean it! Even 0 has its own special, magical meaning on the plane.
comparable quality
recovery from every initial state
no need for heavy computation of inverse matrix. Just forget about this
easy to implement and to understand. Low RAM and ROM footprint. Maybe will even take this challenge to ship it to some ATtiny chip ( for a fixed numbers precision of course - lets curb some masochists out there … do not try this at home )

That’s the hammer! Should you believe it? Of course not! I said there is only one proof - it works. Then, get your piece of a quaternionic body and check out the sources or if you don’t care let this idea die and be reinvented again somewhere in the future.

![](memes/stackoverflow.png)