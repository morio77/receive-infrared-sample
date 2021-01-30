#include <Arduino.h>
#include "M5Atom.h"
#include <IRrecv.h>
#include <IRutils.h>

const auto recvPin = 33;             // 受信モジュールを接続するPIN
const auto captureBufferSize = 1024; // バッファサイズ
const auto timeoutMillSec = 50;      // タイムアウト時間
decode_results results;              // 受信結果を格納する変数

IRrecv irrecv(recvPin, captureBufferSize, timeoutMillSec, false); // 赤外線受信オブジェクト

void setup() {
  Serial.begin(115200);
  irrecv.enableIRIn();
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.print(resultToHumanReadableBasic(&results));
  }

  delay(500);
}