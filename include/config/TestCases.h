// TestCases.h
#ifndef TEST_CASE_LIST_H
#define TEST_CASE_LIST_H

#include "config/GlobalConfig.h"
#include <vector>
#include <string>

namespace Config
{
    struct TestCase
    {
        std::string name;
        std::string M_file;
        std::string C_file;
        std::string K_file;
        bool is_sparse;
    };

    inline std::vector<TestCase> getTestCaseList()
    {
        std::string base = Config::PROBLEM_BASE_PATH;

        return {
            // ========== 小规模演示问题（small_demo）==========
            {"100维对称正定问题",
             base + "/small_demo/sym_pos_def/M.bin", base + "/small_demo/sym_pos_def/C.bin", base + "/small_demo/sym_pos_def/K.bin", true},
            {"100维不对称问题",
             base + "/small_demo/unsymmetric/M.bin", base + "/small_demo/unsymmetric/C.bin", base + "/small_demo/unsymmetric/K.bin", true},
            {"100维对称不定问题",
             base + "/small_demo/sym_indefinite/M.bin", base + "/small_demo/sym_indefinite/C.bin", base + "/small_demo/sym_indefinite/K.bin", true},
            // {"100维对称半正定问题",
            //  base + "/small_demo/sym_semi_pos_def/M.bin", base + "/small_demo/sym_semi_pos_def/C.bin", base + "/small_demo/sym_semi_pos_def/K.bin", true},

            // ========== 工程实际问题（engineering）==========
            // {"1千维发电机转子问题",
            //  base + "/engineering/generator_rotor_1k/M.bin", base + "/engineering/generator_rotor_1k/C.bin", base + "/engineering/generator_rotor_1k/K.bin", true},
            // {"1万维板子问题",
            //  base + "/engineering/plate_10k/M.bin", base + "/engineering/plate_10k/C.bin", base + "/engineering/plate_10k/K.bin", true},
            // {"56万维水轮机问题",
            //  base + "/engineering/turbine_560k/M.bin", base + "/engineering/turbine_560k/C.bin", base + "/engineering/turbine_560k/K.bin", true},
            // {"78万维振动筛问题",
            //  base + "/engineering/vibrating_screen_780k/M.bin", base + "/engineering/vibrating_screen_780k/C.bin", base + "/engineering/vibrating_screen_780k/K.bin", true},

            // ========== 基准测试问题（benchmark）==========
            // {"20万维 spring 问题",
            //  base + "/benchmark/spring_200k/M.bin", base + "/benchmark/spring_200k/C.bin", base + "/benchmark/spring_200k/K.bin", true},
            // {"1万维 damped_beam 问题",
            //  base + "/benchmark/damped_beam_10k/M.bin", base + "/benchmark/damped_beam_10k/C.bin", base + "/benchmark/damped_beam_10k/K.bin", true},
            // {"20万维 acoustic_wave_1d 问题",
            //  base + "/benchmark/acoustic_wave_200k/M.bin", base + "/benchmark/acoustic_wave_200k/C.bin", base + "/benchmark/acoustic_wave_200k/K.bin", true},
            // {"1万维 wiresaw1 问题（C为稠密矩阵）",
            //  base + "/benchmark/wiresaw1_10k/M.bin", base + "/benchmark/wiresaw1_10k/C.bin", base + "/benchmark/wiresaw1_10k/K.bin", true},
            // {"基准测试问题1",
            //  base + "/benchmark/test_prob_1/M.bin", base + "/benchmark/test_prob_1/C.bin", base + "/benchmark/test_prob_1/K.bin", true},
        };
    }
}
#endif // TEST_CASE_LIST_H
