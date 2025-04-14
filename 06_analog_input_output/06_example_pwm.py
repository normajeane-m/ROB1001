import numpy as np
import matplotlib.pyplot as plt

# 시간축 (5ms, 1000 포인트)
t = np.linspace(0, 5, 1000)

# PWM 설정
frequency = 1  # 1Hz (주기: 1초)
duty_cycles = [0.25, 0.5, 0.75]  # 25%, 50%, 75%

plt.figure(figsize=(10, 6))
for i, duty in enumerate(duty_cycles):
    pwm_signal = ((t % (1/frequency)) < (duty / frequency)).astype(float)  # High/Low
    plt.subplot(len(duty_cycles), 1, i + 1)
    plt.plot(t, pwm_signal, drawstyle='steps-post', color='blue')
    plt.ylim(-0.2, 1.2)
    plt.title(f"PWM Signal - Duty Cycle: {int(duty*100)}%")
    plt.ylabel("Signal")
    plt.grid(True)

plt.xlabel("Time (s)")
plt.tight_layout()
plt.show()
