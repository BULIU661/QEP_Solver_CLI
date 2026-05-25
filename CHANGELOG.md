# Changelog

All notable changes to QEP Solver CLI.

## [1.1.0] - 2025-07-28

### Added
- 独立发行版打包，包含预编译 `qep.exe` 及运行时 DLL
- CLI 完整命令参考（8 个选项，7 个使用示例）
- `config.json` 运行时配置，支持求解器选择、参数调整、日志控制
- 问题自动发现：递归扫描 `Problems/` 目录，支持 `problem.json` 元数据
- 自适应参数：基于 K 矩阵条件数自动调整求解策略
- 输出格式细化：4 级残差状态（EXCELLENT / OK / ACCEPTABLE / WARNING）
- 矩阵属性检查（对称性、定性分类、条件数估计）
- Windows UTF-8 控制台支持，CJK 字符宽度计算

### Changed
- 重构：问题发现架构升级，配置架构三层分离（CLI 参数 > 案例覆盖 > 配置文件默认值）
- 重构：核心库配置架构三层分离，移除 I/O 依赖
- 清理：重分类问题数据，清理无用文件

### Fixed
- 改进可移植性：移除硬编码生成器、MKL/Pardiso 条件编译、路径可配置

## [1.0.0] - 2025-06-15

### Added
- 二次特征值问题（QEP）统一求解框架
- 支持 6 种内层线性求解器：SparseLU, PardisoLU, SimplicialLLT, ConjugateGradient, BiCGSTAB, GMRES
- 基于 Spectra 的 Arnoldi 特征值求解器
- Intel MKL 加速支持（PARDISO 直接求解器）
- AVX2 指令集优化
- OpenMP 并行化
- 矩阵 I/O：支持 CSR 二进制格式和文本格式互转
- 14 个预置测试问题（small_demo / benchmark / engineering / user）
- CMake 构建系统，支持条件编译和安装规则
- Eigen 3.4+ / Spectra 1.1+ / nlohmann/json 第三方依赖
