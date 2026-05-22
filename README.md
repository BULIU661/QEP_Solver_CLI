# QEP Solver

基于 **Eigen** 和 **Spectra** 库的稀疏矩阵二次特征值问题（QEP）求解器。

## 问题描述

求解二次特征值问题：

```
(λ²M + λC + K) x = 0
```

其中 M, C, K 为稀疏矩阵，λ 为特征值，x 为特征向量。这类问题广泛存在于结构动力学、声学、转子动力学等工程领域。

## 快速构建

项目已包含 Eigen 和 Spectra 依赖，下载后可直接构建：

```bash
mkdir build && cd build
cmake .. -DQEP_USE_MKL=OFF    # 无 MKL 环境使用此选项
cmake --build . -j4
```

如需 Intel MKL 加速（推荐），配置时确保 MKL 环境可用：

```bash
cmake ..                      # 自动检测 MKL
```

## 运行测试

```bash
./bin/qep_test                # 默认参数运行测试
./bin/qep_test 0.1 15         # 指定移频点 sigma=0.1，求 15 个特征值
```

## 运行示例

```bash
cmake .. -DQEP_BUILD_EXAMPLES=ON
cmake --build . -j4
./bin/simple_example
```

## CMake 配置选项

| 选项 | 默认值 | 说明 |
|------|--------|------|
| `QEP_USE_MKL` | ON | 启用 Intel MKL 加速 |
| `QEP_USE_AVX2` | ON | 启用 AVX2 指令集 |
| `QEP_USE_OPENMP` | ON | 启用 OpenMP 并行 |
| `QEP_BUILD_TEST` | ON | 构建测试程序 |
| `QEP_BUILD_EXAMPLES` | OFF | 构建示例程序 |
| `QEP_INSTALL` | ON | 生成安装规则 |
| `QEP_PROBLEM_BASE_PATH` | `../Problems` | 问题数据文件路径 |

## 项目结构

```
QEP/
├── CMakeLists.txt              # 主构建文件
├── Problems/                   # 测试问题数据（按分类存放）
│   ├── small_demo/             # 小规模演示问题（100维）
│   ├── engineering/            # 工程实际问题（1千~78万维）
│   └── benchmark/              # 基准测试问题
├── include/
│   ├── qep/QEP.h              # 公共接口
│   └── config/                 # 配置头文件
├── src/
│   ├── qep/core/              # 核心求解器实现
│   ├── qep/io/                # 矩阵文件读写
│   ├── qep/utils/             # 工具函数
│   └── test/                  # 测试程序
├── examples/                   # 示例程序
└── third_party/                # 第三方库（Eigen / Spectra）
```

## 问题数据分类

问题数据统一存放在 `Problems/` 目录下，按类别分为三个子目录：

### small_demo/ — 小规模演示问题（100维）

| 子目录 | 问题类型 | 特点 |
|--------|---------|------|
| `sym_pos_def` | 对称正定 | 数值稳定，适合入门测试 |
| `unsymmetric` | 非对称 | 测试非对称问题求解 |
| `sym_indefinite` | 对称不定 | 测试不定问题求解 |
| `test` | 综合测试 | 原测试用例 |

> `sym_semi_pos_def`（对称半正定）数据保留但默认不启用，如需使用取消 `TestCases.h` 中对应注释即可。

### engineering/ — 工程实际问题

| 子目录 | 维度 | 说明 |
|--------|------|------|
| `generator_rotor_1k` | ~1000 | 发电机转子问题 |
| `plate_10k` | ~10000 | 板子振动问题 |
| `turbine_560k` | ~560000 | 水轮机问题 |
| `vibrating_screen_780k` | ~780000 | 振动筛问题 |

### benchmark/ — 基准测试问题

| 子目录 | 维度 | 特点 |
|--------|------|------|
| `spring_200k` | ~200000 | 对称正定，条件数良好，谱分布密集 |
| `damped_beam_10k` | ~10000 | 对称正定，条件数极差 |
| `acoustic_wave_200k` | ~200000 | 非对称 QEP |
| `wiresaw1_10k` | ~10000 | 对称正定，C 为稠密矩阵 |
| `test_prob_1` | - | 额外基准测试 |

## 求解器列表

| 求解器 | 类型 | 依赖 | 适用场景 |
|--------|------|------|---------|
| PardisoLU | 直接法 | MKL | 通用，性能最佳 |
| SparseLU | 直接法 | 无 | 小规模问题 |
| SimplicialLLT | 直接法 | 无 | 对称正定问题 |
| ConjugateGradient | 迭代法 | 无 | 对称正定，内存有限 |
| BiCGSTAB | 迭代法 | 无 | 非对称问题 |
| GMRES | 迭代法 | 无 | 病态问题 |

## 如何添加自己的问题

1. 在 `Problems/` 下创建新目录（如在 `benchmark/` 下），放入 M.bin / C.bin / K.bin（或 .txt 文本格式）
2. 编辑 `include/config/TestCases.h`，在 `getTestCaseList()` 中添加新条目
3. 同时编辑 `include/config/BinaryConvertList.h`，添加文本→二进制转换映射
4. 重新构建并运行测试

## 依赖

| 依赖 | 版本 | 说明 |
|------|------|------|
| CMake | >= 3.20 | 构建系统 |
| C++ 编译器 | C++17 | GCC >= 7, Clang >= 5, MSVC 2019+ |
| Eigen | 3.x | 已包含在 `third_party/eigen` |
| Spectra | 1.x | 已包含在 `third_party/spectra` |
| Intel MKL | 可选 | 加速线性代数运算（强烈推荐） |
