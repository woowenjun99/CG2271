import 'dart:math';

class DirectionManager {
  /// Used to compute the angle to turn the robot based on the x and y of the
  /// joystick value.
  static int computeAngle(double x, double y) {
    /// Do not allow for reverse mode.
    if (y > 0) return 0;

    final double angleInRadians = atan2(y, x);

    final double angleInDegrees = angleInRadians * (180 / pi);

    int offsetAngle = (angleInDegrees + 90).round();

    if (offsetAngle < -90) {
      return -90;
    } else if (offsetAngle > 90) {
      return 90;
    }
    return offsetAngle;
  }
}
