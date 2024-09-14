#include <benchmark/benchmark.h>

#include <random>
#include <vector>

constexpr int size = 800 * 600;
// constexpr int size = 1920*1080;
constexpr int iter = 5;

std::vector<int> init_vector() {
  std::vector<int> in;
  in.reserve(size);

  for (int i = 0; i < size; i++) {
    in.push_back(rand() % 1000);
  }

  return in;
}

static void PreAlloc(benchmark::State &state) {
  srand(42);
  auto in = init_vector();

  std::vector<int> out;

  for (auto _ : state) {
    for (int i = 0; i < iter; i++) {
      out.clear();
      out.resize(in.size());
      memcpy(out.data(), in.data(), sizeof(int) * in.size());
    }

    benchmark::DoNotOptimize(out);
    benchmark::DoNotOptimize(in);
  }
}
// Register the function as a benchmark
BENCHMARK(PreAlloc);

static void NoAlloc(benchmark::State &state) {
  srand(42);
  auto in = init_vector();

  for (auto _ : state) {
    for (int i = 0; i < iter; i++) {
      std::vector<int> out;
      out.resize(in.size());
      memcpy(out.data(), in.data(), sizeof(int) * in.size());
      benchmark::DoNotOptimize(out);
    }

    benchmark::DoNotOptimize(in);
  }
}
BENCHMARK(NoAlloc);

BENCHMARK_MAIN();
