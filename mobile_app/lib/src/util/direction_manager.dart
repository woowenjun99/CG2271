import 'dart:math';

class Payload {
  final bool isForward;
  final int left;
  final int right;

  const Payload({
    required this.isForward,
    required this.left,
    required this.right,
  });

  int _mask(int x) => 1 << x;

  // Computes the payload based on the PWM and the speed to send to the
  // web socket.
  int toInteger() {
    int leftWheel = left;
    int rightWheel = right;
    int payload = leftWheel << 3 | rightWheel;
    if (isForward) payload |= _mask(6);
    return payload;
  }
}

class DirectionManager {
  final double x;
  final double y;
  bool isForward;

  DirectionManager({
    required this.x,
    required this.y,
    this.isForward = false,
  });

  Payload computePayload() {
    // Stop Direction
    if (x == 0 && y == 0) {
      return const Payload(isForward: false, left: 0, right: 0);
    }

    double angle = atan2(y, x) * (180 / pi);

    // Forward Direction
    if (angle >= 0) {
      return Payload(
        isForward: true,
        left: (((180 - angle) / 180) * 8).floor() - 1,
        right: (angle / 180 * 8).round() - 1,
      );
    }

    return Payload(
      isForward: false,
      left: (((-180 - angle) / 180) * 8).floor() - 1,
      right: ((angle / -180) * 8).floor() - 1,
    );
  }
}
