import struct

with open("desantnik5", "rb") as f:
    bytes = f.read()
address, length, name = struct.unpack("HH16s", bytes[:20])
print(address, length, name)
new_bytes = struct.pack("HH", address, length) + bytes[20:]
with open("desantnik5.conv", "wb") as f:
    f.write(new_bytes)