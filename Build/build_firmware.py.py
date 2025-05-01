import struct
import zlib

ML_WEIGHTS = [0.18, 0.15, 0.12]  # X, Y, Recoil

with open('../Firmware/BloodyAIM.bin', 'wb') as f:
    # Bloody firmware header
    f.write(b'BLD\x07\x00\x00\x00\x40\x00\x00\x00')
    
    # ML payload
    f.write(struct.pack('<I', len(ML_WEIGHTS)*4))
    for w in ML_WEIGHTS:
        f.write(struct.pack('<f', w))
    
    # CRC32 validation
    crc = zlib.crc32(f.getbuffer())
    f.write(struct.pack('<I', crc))