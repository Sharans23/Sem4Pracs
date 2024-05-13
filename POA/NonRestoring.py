def deci_to_bin(n):
  """Converts a decimal integer to binary string (without leading '0b')."""
  return bin(n)[2:]

def shift_left(C, AC, Q):
  """Shifts the AC and Q registers left by one bit, updating the Carry bit."""
  C = AC[0]
  AC = AC[1:] + Q[0]
  Q = Q[1:] + '_'
  return C, AC, Q

def operation(C, AC, M):
  """Performs addition or subtraction based on Carry and M."""
  temp = bin(int(C + AC, 2) + int(M, 2))[2:]
  if len(temp) > len(M):
    temp = temp[1:]
  return temp[0], temp[1:]

def non_restoring_division():
  """Performs non-restoring division and prints the quotient and remainder."""
  dividend = deci_to_bin(int(input("Enter the dividend (Q) : ")))
  divisor = deci_to_bin(int(input("Enter the divisor (M) : ")))

  # Initialization
  AC = '0' * (len(dividend) + 1)
  C = '0'
  Q = '0' * (len(divisor) - len(dividend)) + dividend
  M = '0' + divisor

  # Calculate two's complement of divisor
  M_negative = bin(int(''.join(['1' if bit == '0' else '0' for bit in M]), 2) + 1)[2:]

  print("\nInitial C value is :", C)
  print("Initial AC value is :", AC)
  print("Initial Q value is :", Q)
  print("Value of M is :", M)
  print("Two's complement of M :", M_negative)
  print("\n\tC\tAC\tQ\tOperation done")
  print("\t" + C + "\t" + AC + "\t" + Q + "\tInitial values")

  prev_C = '0'  # Initialize previous Carry for the first iteration

  for i in range(len(Q) - 1):  # Exclude the placeholder symbol '_'
    print("Step", (i + 1), ":")
    C, AC, Q = shift_left(C, AC, Q)
    print("\t" + C + "\t" + AC + "\t" + Q + "\tAfter shift left operation")

    if C == '0':
      C, AC = operation(C, AC, M_negative)


  # Handle final remainder based on Carry bit
  if C == '0':  # Positive remainder, final AC holds the remainder
    remainder = int(AC, 2)


  print('\nFinal values')
  print("\t" + C + "\t" + AC + "\t" + Q)
  print("\nRemainder (C, AC):", remainder)  # Print remainder based on Carry bit
  print("Quotient (Q):", int(Q, 2))

non_restoring_division()
