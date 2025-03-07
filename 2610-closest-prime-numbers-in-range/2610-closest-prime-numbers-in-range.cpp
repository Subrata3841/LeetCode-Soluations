class Solution {
public:
    vector<bool> sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false; // 0 and 1 are not prime

    for (int p = 2; p * p <= n; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= n; i += p) {
                is_prime[i] = false;
            }
        }
    }
    return is_prime;
}

// Function to find the closest prime numbers in the given range
vector<int> closestPrimes(int left, int right) {
    vector<bool> is_prime = sieve(right);
    vector<int> primes;

    // Collect primes in the given range
    for (int i = left; i <= right; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }

    // If fewer than two primes exist, return [-1, -1]
    if (primes.size() < 2) {
        return {-1, -1};
    }

    // Find the closest pair of prime numbers
    int min_diff = INT_MAX;
    vector<int> result = {-1, -1};

    for (int i = 1; i < primes.size(); i++) {
        int diff = primes[i] - primes[i - 1];
        if (diff < min_diff) {
            min_diff = diff;
            result = {primes[i - 1], primes[i]};
        }
    }

    return result;
}
};