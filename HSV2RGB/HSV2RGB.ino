byte r, g, b;

int ledRed = 3;
int ledGreen = 4;
int ledBlue = 5;

int hue = 0;
int saturation = 100;
int value = 100;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  HSV_to_RGB(hue, saturation , value, r, g, b);
  analogWrite(ledRed, r);
  analogWrite(ledGreen, g);
  analogWrite(ledBlue, b);
  
}




void HSV_to_RGB(float h, float s, float v, byte &r, byte &g, byte &b) {
  int i;
  float f, p, q, t;

  h = max(0.0f, min(360.0f, h));
  s = max(0.0f, min(100.0f, s));
  v = max(0.0f, min(100.0f, v));
  s /= 100.0f;
  v /= 100.0f;

  if (s == 0) {
    // Achromatic (grey)
    r = g = b = round(v * 255.0f);
    return;
  }

  h /= 60.0f; // sector 0 to 5
  i = floor(h);
  f = h - i; // factorial part of h
  p = v * (1.0f - s);
  q = v * (1.0f - s * f);
  t = v * (1.0f - s * (1.0f - f));
  switch (i) {
    case 0:
      r = round(255.0f * v);
      g = round(255.0f * t);
      b = round(255.0f * p);
      break;
    case 1:
      r = round(255.0f * q);
      g = round(255.0f * v);
      b = round(255.0f * p);
      break;
    case 2:
      r = round(255.0f * p);
      g = round(255.0f * v);
      b = round(255.0f * t);
      break;
    case 3:
      r = round(255.0f * p);
      g = round(255.0f * q);
      b = round(255.0f * v);
      break;
    case 4:
      r = round(255.0f * t);
      g = round(255.0f * p);
      b = round(255.0f * v);
      break;
    default: // case 5:
      r = round(255.0f * v);
      g = round(255.0f * p);
      b = round(255.0f * q);
  }
}
