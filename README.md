# QEP Solver

基于 **Eigen** 和 **Spectra** 库的稀疏矩阵二次特征值问题（QEP）求解器。

## 问题描述

求解二次特征值问题：
```
(λ²M + λC + K) x = 0
```
其中 M, C, K 为稀疏矩阵，λ 为特征值，x 为特征向量。

## 依赖

| 依赖 | 版本 | 说明 |
|------|------|------|
| CMake | >= 3.20 | 构建系统 |
| C++ 编译器 | C++17 支持 | GCC >= 7, Clang >= 5, MSVC 2019+ |
| Eigen | 3.x | 线性代数库（已包含在 `third_party/eigen`） |
| Spectra | 1.x | 特征值求解库（已包含在 `third_party/spectra`） |
| Intel MKL | 可选 | 加速线性代数运算（强烈推荐） |

## 快速开始

### 1. 克隆仓库并准备数据

```bash
git clone <repo_url>
cd QEP
```

> **注意**：问题数据文件（矩阵文件）未包含在仓库中，需要单独放入 `Problems/` 目录。

### 2. 构建

```bash
# 创建构建目录
mkdir build && cd build

# 配置（无 MKL）
cmake .. -DQEP_USE_MKL=OFF

# 配置（有 MKL，默认路径）
cmake ..

# 配置（自定义 MKL 路径）
cmake .. -DMKL_ROOT="/path/to/mkl"

# 构建
cmake --build . -j4
```

### 3. 运行测试

```bash
# 运行测试程序（使用默认参数）
./bin/qep_test

# 指定移频点 sigma 和特征值个数
./bin/qep_test 0.1 15

# 使用测试报告模式
./bin/qep_test 0.0 10
```

### CMake 选项

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
├── CMakeLists.txt           # 主构建文件
├── include/
│   ├── qep/QEP.h           # 公共接口（数据结构与函数声明）
│   └── config/              # 配置头文件
│       ├── GlobalConfig.h   # 全局运行时配置
│       ├── SolverRegistry.h # 求解器注册
│       ├── TestCases.h      # 测试用例定义
│       └── BinaryConvertList.h # 二进制转换列表
├── src/
│   ├── CMakeLists.txt
│   ├── qep/
│   │   ├── core/UnifiedSolver.cpp  # 核心求解器实现
│   │   ├── io/MatrixIO.cpp         # 矩阵文件读写
│   │   └── utils/                  # 工具函数
│   │       ├── ConsoleUtils.cpp    # 控制台格式化
│   │       ├── CreatProblem.cpp    # 问题创建
│   │       ├── MatrixProperties.cpp # 矩阵性质检查
│   │       ├── NumericUtils.cpp    # 数值工具
│   │       ├── PrintUtils.cpp      # 打印工具
│   │       ├── ResidualValidation.cpp # 残差验证
│   │       └── SystemUtils.cpp     # 系统工具
│   └── test/                      # 测试程序
├── examples/                      # 示例程序
├── third_party/                   # 第三方库
│   ├── eigen/
│   └── spectra/
└── Problems/                      # 问题数据（需自行准备）
```

## 支持的求解器

| 求解器 | 类型 | 依赖 | 适用场景 |
|--------|------|------|---------|
| PardisoLU | 直接法 | MKL | 通用，性能最佳 |
| SparseLU | 直接法 | 无 | 小规模问题 |
| SimplicialLLT | 直接法 | 无 | 对称正定问题 |
| ConjugateGradient | 迭代法 | 无 | 对称正定，内存有限 |
| BiCGSTAB | 迭代法 | 无 | 非对称问题 |
| GMRES | 迭代法 | 无 | 病态问题 |

## LICENSE

本项目仅供学习和研究使用。
