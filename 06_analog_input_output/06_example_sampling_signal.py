import numpy as np
import matplotlib.pyplot as plt

# Analog signal
f = 2   # Freq. (5Hz)
T = 1 / f
t_analog = np.linspace(0, 2 * T, 1000)  # Time vector
analog_signal = np.sin(2 * np.pi * f * t_analog)  # Signal

# Sampling
sampling_rate = 5
t_sampled = np.arange(0, 2 * T, 1/sampling_rate)  # Sampled time vector 
sampled_signal = np.sin(2 * np.pi * f * t_sampled)  # Sampled signal

# Visual
plt.figure(figsize=(10, 6))
plt.plot(t_analog, analog_signal, label="Analog Signal", linewidth=2)
plt.stem(t_sampled, sampled_signal, 'r', markerfmt='ro', basefmt=" ", linefmt="r-", label="Sampled Signal")
plt.title("Analog Signal and Sampled Signal")
plt.xlabel("Time [s]")
plt.ylabel("Amplitude")
plt.legend()
plt.grid(True)
plt.show()
