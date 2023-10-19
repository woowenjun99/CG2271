import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:mobile_app/src/app.dart';

Future<void> main() async {
  runApp(const ProviderScope(child: MyApp()));
}
