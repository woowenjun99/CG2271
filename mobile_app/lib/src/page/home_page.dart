import 'dart:math';

import 'package:flutter/material.dart';
import 'package:flutter_joystick/flutter_joystick.dart';
import 'package:web_socket_channel/web_socket_channel.dart';

class MyHomePage extends StatefulWidget {
  final String title;

  const MyHomePage(this.title, {super.key});

  @override
  State<MyHomePage> createState() => _MyHomePageState();
}

class _MyHomePageState extends State<MyHomePage> {
  String direction = "Stop";

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
          children: <Widget>[
            Text("Sent $direction"),
            const SizedBox(height: 24),
            StreamBuilder(
              stream: channel.stream,
              builder: (context, snapshot) {
                return Text(snapshot.hasData
                    ? 'Received ${snapshot.data}'
                    : 'Received no data');
              },
            ),
            const SizedBox(height: 24),
            Joystick(listener: (details) {
              final double x = -details.x;

              final double y = -details.y;

              // Sends a stop signal
              if (x == 0 && y == 0) {
                setState(() => direction = "Stopped");
                channel.sink.add("8");
                return;
              }

              final double angle = atan2(y, x) * (180 / pi);

              // North West
              if (angle > 22.5 && angle <= 67.5) {
                setState(() => direction = "North West");
                channel.sink.add("7");
                return;
              }

              // North
              if (angle > 67.5 && angle <= 112.5) {
                setState(() => direction = "North");
                channel.sink.add("0");
                return;
              }

              // North East
              if (angle > 112.5 && angle <= 157.5) {
                setState(() => direction = "North East");
                channel.sink.add("1");
                return;
              }

              // East
              if (angle > 157.5 || angle <= -157.5) {
                setState(() => direction = "East");
                channel.sink.add("2");
                return;
              }

              // South East
              if (angle > -157.5 && angle <= -112.5) {
                setState(() => direction = "South East");
                channel.sink.add("3");
                return;
              }

              // South
              if (angle <= -67.5 && angle > -112.5) {
                setState(() => direction = "South");
                channel.sink.add("4");
                return;
              }

              // South West
              if (angle <= -22.5 && angle > -67.5) {
                setState(() => direction = "South West");
                channel.sink.add("5");
                return;
              }

              // West
              setState(() => direction = "West");
              channel.sink.add("6");
              return;
            }),
            const SizedBox(height: 24),
            TextButton(
              child: const Text("Terminate music"),
              onPressed: () => channel.sink.add("16"),
            ),
            const SizedBox(height: 24),
            TextButton(
              child: const Text("Pause music"),
              onPressed: () => channel.sink.add("32"),
            )
          ],
        ),
      ),
    );
  }
}
