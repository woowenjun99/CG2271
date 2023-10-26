class Payload {
  final bool isForward;
  final bool isBackward;
  final bool isLeft;
  final bool isRight;
  final bool isCompleted;
  final bool isPaused;

  const Payload({
    required this.isBackward,
    required this.isForward,
    required this.isLeft,
    required this.isRight,
    required this.isCompleted,
    required this.isPaused,
  });

  int generateBinary() {
    int binary = 0;

    if (isForward) {
      binary |= 1 << 1;
    }

    if (isLeft) {
      binary |= 1 << 2;
    }

    if (isBackward) {
      binary |= 1 << 3;
    }

    if (isRight) {
      binary |= 1 << 4;
    }

    if (isCompleted) {
      binary |= 1 << 5;
    }

    if (isPaused) {
      binary |= 1 << 6;
    }

    return binary;
  }
}
