import 'package:flutter/material.dart';
import 'package:mobile_app/src/util/direction_manager.dart';
import 'package:web_socket_channel/web_socket_channel.dart';

class MyHomePage extends StatefulWidget {
  final String title;

  const MyHomePage(this.title, {super.key});

  @override
  State<MyHomePage> createState() => _MyHomePageState();
}

class _MyHomePageState extends State<MyHomePage> {
  @override
  Widget build(BuildContext context) {
    WebSocketChannel channel =
        WebSocketChannel.connect(Uri.parse("ws://${widget.title}"));

    return Scaffold(
      appBar: AppBar(
        backgroundColor: Theme.of(context).colorScheme.inversePrimary,
        title: Text(widget.title),
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          crossAxisAlignment: CrossAxisAlignment.center,
          children: <Widget>[
            StreamBuilder(
              stream: channel.stream,
              builder: (context, snapshot) {
                return Text(snapshot.hasData ? '${snapshot.data}' : '');
              },
            ),
            Row(
              mainAxisAlignment: MainAxisAlignment.center,
              children: [
                TextButton(
                  onPressed: () {
                    int binary = const Payload(
                      isForward: true,
                      isBackward: false,
                      isLeft: true,
                      isRight: false,
                      isCompleted: false,
                      isPaused: false,
                    ).generateBinary();

                    channel.sink.add("$binary");
                  },
                  child: const Text("Top Left"),
                ),
                TextButton(
                  onPressed: () {
                    int binary = const Payload(
                      isForward: true,
                      isBackward: false,
                      isLeft: false,
                      isRight: false,
                      isCompleted: false,
                      isPaused: false,
                    ).generateBinary();

                    channel.sink.add("$binary");
                  },
                  child: const Text("Top"),
                ),
                TextButton(
                  onPressed: () {
                    int binary = const Payload(
                      isForward: false,
                      isBackward: false,
                      isLeft: true,
                      isRight: true,
                      isCompleted: false,
                      isPaused: false,
                    ).generateBinary();

                    channel.sink.add("$binary");
                  },
                  child: Text("Top Right"),
                )
              ],
            ),
            Row(
              mainAxisAlignment: MainAxisAlignment.center,
              children: [
                TextButton(
                  onPressed: () {
                    int binary = const Payload(
                      isForward: false,
                      isBackward: false,
                      isLeft: true,
                      isRight: false,
                      isCompleted: false,
                      isPaused: false,
                    ).generateBinary();

                    channel.sink.add("$binary");
                  },
                  child: const Text("Left"),
                ),
                TextButton(
                  onPressed: () {
                    int binary = const Payload(
                      isForward: false,
                      isBackward: false,
                      isLeft: false,
                      isRight: false,
                      isCompleted: true,
                      isPaused: false,
                    ).generateBinary();

                    channel.sink.add("$binary");
                  },
                  child: const Text("Change Music"),
                ),
                TextButton(
                  onPressed: () {
                    int binary = const Payload(
                      isForward: false,
                      isBackward: false,
                      isLeft: false,
                      isRight: true,
                      isCompleted: false,
                      isPaused: false,
                    ).generateBinary();

                    channel.sink.add("$binary");
                  },
                  child: const Text("Right"),
                )
              ],
            ),
            Row(
              mainAxisAlignment: MainAxisAlignment.center,
              children: [
                TextButton(
                  onPressed: () {
                    int binary = const Payload(
                      isForward: false,
                      isBackward: true,
                      isLeft: true,
                      isRight: false,
                      isCompleted: false,
                      isPaused: false,
                    ).generateBinary();

                    channel.sink.add("$binary");
                  },
                  child: const Text("Reverse Left"),
                ),
                TextButton(
                  onPressed: () {
                    int binary = const Payload(
                      isForward: false,
                      isBackward: true,
                      isLeft: false,
                      isRight: false,
                      isCompleted: false,
                      isPaused: false,
                    ).generateBinary();

                    channel.sink.add("$binary");
                  },
                  child: const Text("Reverse"),
                ),
                TextButton(
                  onPressed: () {
                    int binary = const Payload(
                      isForward: false,
                      isBackward: true,
                      isLeft: false,
                      isRight: true,
                      isCompleted: false,
                      isPaused: false,
                    ).generateBinary();

                    channel.sink.add("$binary");
                  },
                  child: const Text("Reverse Right"),
                ),
              ],
            ),
            TextButton(
                onPressed: () {
                  int binary = const Payload(
                    isForward: false,
                    isBackward: false,
                    isLeft: false,
                    isRight: false,
                    isCompleted: false,
                    isPaused: true,
                  ).generateBinary();

                  channel.sink.add("$binary");
                },
                child: const Text("Pause Music"))
          ],
        ),
      ),
    );
  }
}
