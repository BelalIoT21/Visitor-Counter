# Visitor Counter - Physical Location Tracking 🏬📊

An Arduino-based bi-directional visitor counter system designed to track real-time occupancy in physical locations such as malls, stores, offices, and public spaces. Originally developed during the COVID-19 pandemic to help enforce capacity limits and maintain safe occupancy levels.

![Arduino](https://img.shields.io/badge/Arduino-Compatible-00979D?logo=arduino)
![C++](https://img.shields.io/badge/C++-Project-00599C?logo=c%2B%2B)
![License](https://img.shields.io/badge/License-MIT-green)
[![GitHub stars](https://img.shields.io/github/stars/BelalIoT21/Visitor-Counter)](https://github.com/BelalIoT21/Visitor-Counter/stargazers)

## 🎯 Project Overview

This Arduino project uses infrared (IR) sensors to detect people entering and exiting a physical location, displaying the current occupancy count on a 16x2 LCD screen. The system provides real-time tracking and visual warnings when capacity limits are reached.

**Use Cases:**
- Shopping malls and retail stores
- Office buildings and conference rooms
- Restaurants and cafes
- Libraries and museums
- Any public space requiring occupancy monitoring

## ✨ Key Features

- **Bi-directional Counting**: Accurately tracks people entering and exiting
- **Real-time Display**: 16x2 LCD shows current occupancy count
- **Capacity Warnings**: Scrolling alert message when limit is exceeded
- **Auto-correction**: Prevents negative counts and enforces maximum limits
- **Simple Hardware**: Uses common Arduino components
- **Low Cost**: Affordable solution for small to medium businesses
- **Easy Installation**: Simple setup with minimal wiring

## 🛠️ Hardware Requirements

### Components Needed

| Component | Quantity | Description |
|-----------|----------|-------------|
| Arduino Uno/Mega | 1 | Main microcontroller board |
| 16x2 LCD Display | 1 | Character LCD with backlight |
| IR Sensors | 2 | For entry and exit detection |
| Resistors | 2-4 | Pull-up/pull-down resistors |
| Breadboard | 1 | For prototyping connections |
| Jumper Wires | 20+ | Male-to-male connections |
| Power Supply | 1 | 9V adapter or USB power |

### Pin Configuration

```
LCD Connections:
- RS  → Pin 12
- EN  → Pin 11
- D4  → Pin 5
- D5  → Pin 4
- D6  → Pin 3
- D7  → Pin 2

IR Sensor Connections:
- Entry Sensor  → Pin 15 (Input)
- Entry Power   → Pin 16 (Output/HIGH)
- Exit Sensor   → Pin 14 (Input)
- Exit Power    → Pin 17 (Output/HIGH)
```

## 🔌 Circuit Diagram

```
                    Arduino Uno
                   ┌───────────┐
Entry IR Sensor ───┤ D15   D12 ├─── LCD RS
Entry Power    ────┤ D16   D11 ├─── LCD EN
Exit IR Sensor ────┤ D14    D5 ├─── LCD D4
Exit Power     ────┤ D17    D4 ├─── LCD D5
                   │        D3 ├─── LCD D6
                   │        D2 ├─── LCD D7
                   │       GND ├─── GND (LCD & Sensors)
                   │       5V  ├─── VCC (LCD & Sensors)
                   └───────────┘
```

## 📥 Installation

### 1. Hardware Setup

```bash
# Assemble the circuit according to the pin configuration
# Connect IR sensors at entry and exit points
# Mount LCD display in visible location
# Power the Arduino via USB or 9V adapter
```

### 2. Software Setup

```bash
# Install Arduino IDE
# Download from: https://www.arduino.cc/en/software

# Install LiquidCrystal Library (usually pre-installed)
# Sketch → Include Library → LiquidCrystal
```

### 3. Upload Code

```bash
# Clone this repository
git clone https://github.com/BelalIoT21/Visitor-Counter.git

# Open VisitorCounter.ino in Arduino IDE
# Select correct board: Tools → Board → Arduino Uno
# Select correct port: Tools → Port → [Your Arduino Port]
# Click Upload button (→)
```

## 🚀 Quick Start

### Basic Operation

1. **Power On**: Connect Arduino to power source
2. **Display Shows**: "PEOPLE IN: 0"
3. **Person Enters**: Count increases by 1
4. **Person Exits**: Count decreases by 1
5. **Warning Triggered**: When count ≥ 5, scrolling warning appears

### Calibration

```cpp
// Adjust these values in the code:

// Maximum capacity (currently set to 1000)
ppl = constrain(ppl, 0, 1000);  // Change 1000 to your max capacity

// Warning threshold (currently set to 5)
if (ppl >= 5){  // Change 5 to your warning threshold

// Detection delay (currently 500ms)
delay(500);  // Adjust to prevent double counting
```

## ⚙️ Configuration

### Adjusting Capacity Limits

Edit the Arduino code to set your specific capacity requirements:

```cpp
void loop() {
  // Set maximum capacity limit
  ppl = constrain(ppl, 0, 500);  // Example: 500 person limit
  
  // Display current count
  lcd.setCursor(0, 0);
  lcd.print("PEOPLE IN:");
  lcd.setCursor(11, 0);
  lcd.print(ppl);
}

void loop1(){
  // Set warning threshold (e.g., 80% of capacity)
  if (ppl >= 400){  // Warning at 400 people
     lcd.setCursor(0, 1);
     lcd.print(Scroll_LCD_Left("WARNING! Capacity limit reached"));
     delay(350);
  }
}
```

### Custom Warning Messages

```cpp
// Modify warning message
String warningMsg = "WARNING! Maximum capacity reached. Please wait.";
lcd.print(Scroll_LCD_Left(warningMsg));

// Add different threshold messages
if (ppl >= 450){
  lcd.print(Scroll_LCD_Left("CRITICAL! No entry allowed"));
}
else if (ppl >= 400){
  lcd.print(Scroll_LCD_Left("WARNING! Near capacity"));
}
```

## 🧪 Testing & Simulation

### Online Simulators

**Tinkercad Simulation:**
- URL: https://www.tinkercad.com/things/jRXV8hTxXXP-bi-directional-visitor-counter/editel
- Full circuit simulation with virtual components
- Test functionality before building physical circuit

**Wokwi Simulation:**
- URL: https://wokwi.com/projects/328725759024693842
- Arduino code testing environment
- Real-time LCD display simulation

### Physical Testing

```bash
# Test entry sensor
1. Wave hand in front of entry sensor
2. Observe count increase on LCD
3. Verify 500ms delay prevents double counting

# Test exit sensor
1. Wave hand in front of exit sensor
2. Observe count decrease on LCD
3. Verify count doesn't go below 0

# Test warning message
1. Trigger sensors until count reaches threshold
2. Observe scrolling warning message
3. Verify message clears when count drops
```

## 📊 System Operation

### Counting Logic

```
Entry Detection:
┌─────────┐
│ Person  │
│ Enters  │──→ IR Sensor Triggered ──→ Count + 1
└─────────┘

Exit Detection:
┌─────────┐
│ Person  │
│ Exits   │──→ IR Sensor Triggered ──→ Count - 1
└─────────┘

Count Display:
┌──────────────────┐
│  PEOPLE IN: 25   │
│  PLEASE VISIT    │
└──────────────────┘

Warning Display:
┌──────────────────┐
│  PEOPLE IN: 402  │
│ WARNING! There..│← Scrolling text
└──────────────────┘
```

## 🔧 Troubleshooting

### Common Issues

**LCD Not Displaying:**
- Check all LCD pin connections
- Adjust contrast potentiometer
- Verify 5V power supply to LCD

**Sensors Not Working:**
- Check sensor power (pins 16 & 17 set to HIGH)
- Verify sensor alignment at entry/exit points
- Test individual sensors with LED indicator

**Double Counting:**
- Increase delay time in code (currently 500ms)
- Adjust sensor positioning for better detection
- Add physical barriers to guide traffic flow

**Count Goes Negative:**
- Already prevented in code with `constrain(ppl, 0, 1000)`
- Check exit sensor triggering accidentally

## 📈 Future Enhancements

### Possible Upgrades

- **WiFi Integration**: ESP32/ESP8266 for remote monitoring
- **Data Logging**: SD card module to log occupancy over time
- **Multiple Displays**: Add external displays at entry points
- **Alarm System**: Buzzer alert when capacity exceeded
- **Temperature Screening**: Integrate IR temperature sensor
- **Access Control**: Automatic door lock when at capacity

### Code Improvements

```cpp
// Add timestamp logging
// Add wireless data transmission
// Implement EEPROM for persistent count storage
// Add admin reset button
// Create daily/weekly occupancy reports
```

## 🤝 Contributing

Contributions are welcome! Here's how you can help:

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/improvement`)
3. Test your changes thoroughly
4. Commit your changes (`git commit -m 'Add new feature'`)
5. Push to the branch (`git push origin feature/improvement`)
6. Open a Pull Request

## 📄 License

This project is licensed under the MIT License - see the LICENSE file for details.

## 🙏 Acknowledgments

- Developed during COVID-19 pandemic for public safety
- Built with Arduino community support
- Thanks to all contributors and testers

## 📞 Contact

**Developer**: Belal IoT  
**GitHub**: [@BelalIoT21](https://github.com/BelalIoT21)

### Support
- 🐛 **Bug Reports**: [GitHub Issues](https://github.com/BelalIoT21/Visitor-Counter/issues)
- 💡 **Feature Requests**: [GitHub Discussions](https://github.com/BelalIoT21/Visitor-Counter/discussions)

---

⭐ **Star this repository if it helped you track occupancy safely!**

🏥 *Built for safer public spaces during COVID-1
