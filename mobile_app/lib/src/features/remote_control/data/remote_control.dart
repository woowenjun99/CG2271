import 'package:dio/dio.dart';
import 'package:riverpod_annotation/riverpod_annotation.dart';

part 'remote_control.g.dart';

enum Direction {
  forward,
  reverse,
  left,
  right,
  stop,
}

class RemoteControl {
  final Dio dio;

  RemoteControl(this.dio);

  Future<bool> checkConnection(String url) async {
    final Response response = await dio.get("$url/status");

    if (response.statusCode! >= 200 || response.statusCode! <= 299) {
      return true;
    }

    return false;
  }

  Future<String> move(String url, Direction direction, int speed) async {
    if (speed < 0) {
      speed = 0;
    } else if (speed > 255) {
      speed = 255;
    }

    final Response response = await dio.get(url, queryParameters: {
      "direction": direction.name,
      "speed": speed,
    });

    if (response.statusCode! >= 200 || response.statusCode! <= 299) {
      return response.data.toString();
    }

    throw Exception("Network error!");
  }
}

@Riverpod(keepAlive: true)
RemoteControl remoteControl(ref) {
  return RemoteControl(Dio());
}
