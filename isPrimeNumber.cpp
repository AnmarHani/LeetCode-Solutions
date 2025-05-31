bool is_prime(int num) {
  if(num <= 1) return false;

  for(size_t i = 2; i < num; i++) {
    if(num % i == 0) return false; // it is divisible by any of the 2..num-1 numbers, that means it is not prime because it accepts divison by another number than itself (and 1).
  }
  return true;
}
