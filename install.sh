#!/usr/bin/sh

if [ $(id -u) -ne 0 ]; then
  echo "[lann] root permissions are needed"
  exit 1
fi

echo "[lann] copying raylib.so to /usr/share/lann..."
cp raylib.so /usr/share/lann/

echo "[lann] done!"
