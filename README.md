# 𝜁 filter
## Overview

This is implementation of 𝜁 filter - another boring attitude estimator like Kalman Filter that proves renormalization is a lie. It is quite interesting to see filters which use quaternions ( or any complex/hyper-complex numbers ) explicitly in the state don't necesserry need to preserve they unit length. Also, implications of this goes far beyond attitude estimation and suggests there still exist missing or yet not disovered puzzles in probability. Read [ What people still don’t understand about rotations?](docs/README.md) for more details.

## How I can run it?

Implementation is work in progress as for now but the current state suggests everything will be dockerized for greater portability. Right now you can only run tests of C lib implementation. For future planning to extend it to multiple targets:

```
docker build --target C-test .
```

Want to run this without docker? There is a CMakeLists.txt prepared in libs/C directory. Tests target uses gtest library so you need to have it installed before compiling tests. For the plain filter build zero dependency is expected - as I said right now there is only test target but be patient, more will come soon.