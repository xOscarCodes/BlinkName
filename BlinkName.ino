#include <Arduino.h>
#include <string.h>

#define led_pin 12
#define one_unit 1000
#define three_units 3000

typedef struct
{
  String letter;
  String morse;
} dict;

const dict code[]{{"a", ".-"}, {"b", "-..."}, {"c", "-.-."}, {"d", "-.."}, {"e", "."}, {"f", "..-."}, {"g", "--."}, {"h", "...."}, {"i", ".."}, {"j", ".---"}, {"k", "-.-"}, {"l", ".-.."}, {"m", "--"}, {"n", "-."}, {"o", "---"}, {"p", ".--."}, {"q", "--.-"}, {"r", ".-."}, {"s", "..."}, {"t", "-"}, {"u", "..-"}, {"v", "...-"}, {"w", ".--"}, {"x", "-..-"}, {"y", "-.--"}, {"z", "--.."}};

void setup()
{
  pinMode(led_pin, OUTPUT);
  String names = "charanpreet";
  blink_name(names);
  digitalWrite(led_pin, LOW);
}

void loop()
{

}

String generate_morse(String name)
{
  String morse_code;

  for (uint16_t i = 0; i < sizeof(name); i++)
  {
    for (uint16_t j = 0; j < sizeof(code)/sizeof(dict); j++)
    {
      if (String(name[i]) == code[j].letter)
      {
        morse_code += code[j].morse;
      }
    }
    morse_code += " ";
  }
  return morse_code;
}

void blink_name(String name)
{
  String morse_code = generate_morse(name);

  for (uint16_t i = 0; i < morse_code.length(); i++)
  {
    if (morse_code[i] == '-')
    {
      blink_dash();
    }
    else if (morse_code[i] == '.')
    {
      blink_dot();
    }
    else if (morse_code[i] == ' ')
    {
      delay(3000);
    }
  }
}

void blink_dot()
{
  digitalWrite(led_pin, HIGH);
  delay(one_unit);
  digitalWrite(led_pin, LOW);
  delay(one_unit);
}

void blink_dash()
{
  digitalWrite(led_pin, HIGH);
  delay(three_units);
  digitalWrite(led_pin, LOW);
  delay(one_unit);
}
