# 更新日志

QEP Solver CLI 所有重要变更记录。

## [1.1.0] - 2026-05-26

### 新增

- 独立发行包，预编译 `qep.exe` + 7 个运行时 DLL（MKL + VC Runtime），解压即用
- 14 个预置测试案例（small_demo / benchmark / engineering / user），矩阵规模 100 ~ 780k
- `config.json` 运行时配置驱动，切换问题、选择求解器、调整参数均无需重新编译
- 问题自动发现：递归扫描 `Problems/` 目录，识别 M.bin / C.bin / K.bin，支持 `problem.json` 元数据
- 4 级残差验证状态（EXCELLENT / OK / ACCEPTABLE / WARNING）
- 自适应参数：基于 K 矩阵条件数自动调整求解策略
- 矩阵属性诊断（对称性、定性分类、条件数估计）
- `config.schema.json` 配置文件 JSON Schema 校验
- MIT 开源许可证
- Windows UTF-8 控制台支持，CJK 字符宽度计算

### 修复

- 修复 `active_cases` 与 `problem.json` 中 name 不匹配导致无法发现测试案例的问题
- 修复错误信息中路径显示为未解析的相对路径的问题
- 修复问题目录扫描异常被静默吞掉的问题，现正确输出异常详情

### 改进

- 二进制文件（DLL / exe）统一移至 `bin/` 目录，根目录整洁
- 移除冗余 `mkl_def.2.dll`（AVX2 默认内核已覆盖，减少 32 MB）
- `.gitignore` 规范化，忽略构建产物与 IDE 临时文件
- 目录名规范化：`Problems/user's problems/` → `Problems/user/`
- 删除冗余存根头文件 `CreateProblem.h`
- 求解器注册表模式，添加新求解器无需修改调度代码
- README 全面修订：修正目录结构、CLI 示例、构建选项，补充许可证声明

### 重构

- 配置架构三层分离（CLI 参数 > 案例覆盖 > 配置文件默认值）
- 问题发现架构升级，移除硬编码路径依赖
- MKL / Pardiso 条件编译，跨平台可移植

## [1.0.0] - 2025-06-15

### 新增

- 二次特征值问题（QEP）统一求解框架
- 位移求逆 Arnoldi 特征值求解器（基于 Spectra）
- 6 种内层线性求解器：SparseLU、PardisoLU、SimplicialLLT、ConjugateGradient、BiCGSTAB、GMRES
- Intel MKL 加速支持（PARDISO 直接求解器 + BLAS）
- AVX2 指令集优化与 OpenMP 并行化
- 矩阵 I/O：CSR 二进制格式与文本格式互转
- CMake 构建系统，支持条件编译与安装规则
- Eigen 3.4+ / Spectra 1.1+ / nlohmann/json 第三方依赖
- CLI 命令参考（8 个选项，7 个使用示例）

### 改进

- 输出格式细化：逐特征值残差验证表格
- 问题数据重分类，清理无用文件
