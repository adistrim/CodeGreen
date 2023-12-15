import 'dart:async';
import 'dart:convert';
import 'package:flutter/material.dart';
import 'package:flutter/services.dart';
import 'package:http/http.dart' as http;

const String thingSpeakChannelID = 'yourchannelid';
const String thingSpeakAPIKey = 'yourkey';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatefulWidget {
  const MyApp({super.key});

  @override
  _MyAppState createState() => _MyAppState();
}

class _MyAppState extends State<MyApp> {
  Timer? _timer;
  double? _latestValue;

  // Added variables for dropdown menu and text field
  int _selectedDuration = 2;

  List<int> predictedValues = [32, 31, 29, 24, 18, 19];

  int getPredictedValue() {
    int selectedIndex = (_selectedDuration / 2).round() - 1;
    return predictedValues[selectedIndex];
  }

  @override
  void initState() {
    super.initState();
    _getData();
    _timer = Timer.periodic(const Duration(seconds: 10), (_) => _getData());
  }

  @override
  void dispose() {
    _timer?.cancel();
    super.dispose();
  }

  Future<void> _getData() async {
    // Same logic as before
    try {
      final url = Uri.parse(
          'https://api.thingspeak.com/channels/$thingSpeakChannelID/feeds/last.json?api_key=$thingSpeakAPIKey');
      final response = await http.get(url);

      if (response.statusCode == 200) {
        final dataMap = jsonDecode(response.body);
        if (dataMap.containsKey('field1')) {
          final data = dataMap['field1'];
          print('Data: $data');
          setState(() {
            _latestValue = double.parse(data);
          });
        } else {
          print('Error: field1 key not found in JSON response');
          // Handle this error case
        }
      } else {
        print('Error: ${response.reasonPhrase}');
        // Handle other HTTP error codes
      }
    } catch (e) {
      print('Error: $e');
      // Handle other errors
    }
  }

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      home: Scaffold(
        appBar: AppBar(
          title: Text('IoT Project - CodeGreen'),
          backgroundColor: Colors.lightGreen, // Use predefined color
        ),
        body: Center(
          child: Column(
            mainAxisAlignment: MainAxisAlignment.center,
            children: [
              // First section
              Text(
                'Latest Pollution level:',
                style: TextStyle(fontSize: 24),
              ),
              SizedBox(height: 16),
              _latestValue != null
                  ? Text(
                      '${_latestValue?.round()}%',
                      style:
                          TextStyle(fontSize: 32, fontWeight: FontWeight.bold),
                    )
                  : CircularProgressIndicator(), // Show a loading indicator
              SizedBox(height: 32),

              // Second section
              Row(
                mainAxisAlignment: MainAxisAlignment.center,
                children: [
                  Text('Interval:'),
                  SizedBox(width: 8),
                  DropdownButton<int>(
                    value: _selectedDuration,
                    items: [
                      for (int i = 2; i <= 12; i += 2)
                        DropdownMenuItem(value: i, child: Text('$i hours')),
                    ],
                    onChanged: (int? value) {
                      if (value != null) {
                        setState(() {
                          _selectedDuration = value;
                        });
                      }
                    },
                  ),
                ],
              ),
              Row(
                mainAxisAlignment: MainAxisAlignment.center,
                children: [
                const SizedBox(width: 16),
                const Text('Predicted Pollution level:'),
                const SizedBox(width: 16),
                Text(
                  getPredictedValue().toString(),
                  style: const TextStyle(fontSize: 16),
                ),
              ],
              )
            ],
          ),
        ),
      ),
    );
  }
}
