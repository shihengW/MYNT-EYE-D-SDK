# Get IMU calibration parameters {#get_imu_params}

Use ``GetMotionIntrinsics()`` and ``GetMotionExtrinsics`` to get current IMU calibration parameters.

Reference code snippet:

```
auto intrinsics = cam.GetMotionIntrinsics(&in_ok);
std::cout << "Motion Intrinsics: {" << intrinsics << "}" << std::endl;
out << "Motion Intrinsics: {" << intrinsics << "}" << std::endl;
```

The result will be saved in the current file directory.Reference result on Linux:

```
Motion Intrinsics: {accel: {scale: [1.00205999990004191, 0.00000000000000000, 0.00000000000000000, 0.00000000000000000, 1.00622999999999996, 0.00000000000000000, 0.00000000000000000, 0.00000000000000000, 1.00171999999999994], assembly: [1.00000000000000000, 0.00672262000000000, -0.00364474000000000, 0.00000000000000000, 1.00000000000000000, 0.00101348000000000, -0.00000000000000000, 0.00000000000000000, 1.00000000000000000, 1.00000000000000000], drift: [0.00000000000000000, 0.00000000000000000, 0.00000000000000000], noise: [0.00000000000000000, 0.00000000000000000, 0.00000000000000000], bias: [0.00000000000000000, 0.00000000000000000, 0.00000000000000000], x: [0.00856165620000000, -0.00009840052800000], y: [0.05968393300000000, -0.00130967680000000], z: [0.01861442050000000, -0.00016033523000000]}, gyro: {scale: [1.00008999999999992, 0.00000000000000000, 0.00000000000000000, 0.00000000000000000, 0.99617599999999995, 0.00000000000000000, 0.00000000000000000, 0.00000000000000000, 1.00407000000000002], assembly: [1.00000000000000000, -0.00700362000000000, -0.00326206000000000, 0.00549571000000000, 1.00000000000000000, 0.00224867000000000, 0.00236088000000000, 0.00044507800000000, 1.00000000000000000, 1.00000000000000000], drift: [0.00000000000000000, 0.00000000000000000, 0.00000000000000000], noise: [0.00000000000000000, 0.00000000000000000, 0.00000000000000000], bias: [0.00000000000000000, 0.00000000000000000, 0.00000000000000000], x: [0.18721455299999998, 0.00077411070000000], y: [0.60837032000000002, -0.00939702710000000], z: [-0.78549276000000001, 0.02584820200000000]}}
```

Complete code examples, see [get_imu_params.cc](https://github.com/slightech/MYNT-EYE-D-SDK/blob/master/samples/src/get_imu_params.cc).