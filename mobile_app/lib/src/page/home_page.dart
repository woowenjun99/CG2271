import 'package:flutter/material.dart';
import 'package:flutter_joystick/flutter_joystick.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';

import 'package:mobile_app/src/util/direction_manager.dart';

class MyHomePage extends ConsumerStatefulWidget {
  const MyHomePage({super.key, required this.title});

  final String title;

  @override
  ConsumerState<MyHomePage> createState() => _MyHomePageState();
}

class _MyHomePageState extends ConsumerState<MyHomePage> {
  final TextEditingController _ipAddressController = TextEditingController();

  @override
  void dispose() {
    _ipAddressController.dispose();
    super.dispose();
  }

  void _incrementCounter() {}

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        backgroundColor: Theme.of(context).colorScheme.inversePrimary,
        title: Text(widget.title),
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: <Widget>[
            TextFormField(
              controller: _ipAddressController,
              decoration:
                  const InputDecoration(labelText: "Enter the IP address"),
            ),
            const SizedBox(height: 24),

            /// TODO: Configure the period so that it is smooth.
            Joystick(listener: (details) {
              print("x: ${details.x}");
              print("y: ${details.y}");
              print("${DirectionManager.computeAngle(details.x, details.y)}");
            })
          ],
        ),
      ),
      floatingActionButton: FloatingActionButton(
        onPressed: _incrementCounter,
        tooltip: 'Increment',
        child: const Icon(Icons.add),
      ),
    );
  }
}
