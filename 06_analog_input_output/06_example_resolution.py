import numpy as np
import matplotlib.pyplot as plt

# 아날로그 신호: 사인파
t = np.linspace(0, 1, 1000)  # 0초~1초, 총 1000 포인트
analog_signal = 0.5 * np.sin(2 * np.pi * t) + 0.5  # 0~1 범위의 사인파 (정규화됨)

# ADC 함수: 해상도에 따라 디지털 값으로 양자화
def adc(signal, bits):
    levels = 2 ** bits
    quantized = np.round(signal * (levels - 1)) / (levels - 1)
    return quantized

# 해상도 별로 그래프 그리기
resolutions = [2]#, 3, 8]

plt.figure(figsize=(12, 8))
for i, bits in enumerate(resolutions):
    quantized_signal = adc(analog_signal, bits)
    plt.subplot(1, len(resolutions), i + 1)
    plt.plot(t, analog_signal, label="Analog Signal", alpha=0.5, linestyle='--', color='gray')
    plt.step(t, quantized_signal, label=f"{bits}-bit ADC Output", where='mid')
    #line_analog, = plt.plot(t, analog_signal, linestyle='--', color='gray', label='Analog Signal')  # 회색 점선
    #line_digital, = plt.step(t, adc(analog_signal, 2), where='mid', color='blue', label='Digital (Quantized)')
    plt.ylim(-0.1, 1.1)
    plt.title(f"{bits}-bit Resolution ADC")
    plt.grid(True)

plt.legend()
#plt.tight_layout()
plt.show()
