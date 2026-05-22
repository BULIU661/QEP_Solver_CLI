// BinaryConvertList.h
#ifndef BINARY_CONVERT_LIST_H
#define BINARY_CONVERT_LIST_H

#include "config/GlobalConfig.h"
#include <vector>
#include <string>
#include <utility>
namespace Config
{
    inline std::vector<std::pair<std::string, std::string>> getBinaryConvertList()
    {
        std::string base = Config::PROBLEM_BASE_PATH;
        return {
            // ========== small_demo (文本->二进制转换) ==========
            {base + "/small_demo/test/M.txt", base + "/small_demo/test/M.bin"},
            {base + "/small_demo/test/K.txt", base + "/small_demo/test/K.bin"},
            {base + "/small_demo/test/C.txt", base + "/small_demo/test/C.bin"},
            {base + "/small_demo/sym_pos_def/M.txt", base + "/small_demo/sym_pos_def/M.bin"},
            {base + "/small_demo/sym_pos_def/K.txt", base + "/small_demo/sym_pos_def/K.bin"},
            {base + "/small_demo/sym_pos_def/C.txt", base + "/small_demo/sym_pos_def/C.bin"},
            {base + "/small_demo/sym_semi_pos_def/M.txt", base + "/small_demo/sym_semi_pos_def/M.bin"},
            {base + "/small_demo/sym_semi_pos_def/K.txt", base + "/small_demo/sym_semi_pos_def/K.bin"},
            {base + "/small_demo/sym_semi_pos_def/C.txt", base + "/small_demo/sym_semi_pos_def/C.bin"},
            {base + "/small_demo/unsymmetric/M.txt", base + "/small_demo/unsymmetric/M.bin"},
            {base + "/small_demo/unsymmetric/K.txt", base + "/small_demo/unsymmetric/K.bin"},
            {base + "/small_demo/unsymmetric/C.txt", base + "/small_demo/unsymmetric/C.bin"},
            {base + "/small_demo/sym_indefinite/M.txt", base + "/small_demo/sym_indefinite/M.bin"},
            {base + "/small_demo/sym_indefinite/K.txt", base + "/small_demo/sym_indefinite/K.bin"},
            {base + "/small_demo/sym_indefinite/C.txt", base + "/small_demo/sym_indefinite/C.bin"},

            // ========== engineering ==========
            {base + "/engineering/generator_rotor_1k/C.txt", base + "/engineering/generator_rotor_1k/C.bin"},
            {base + "/engineering/generator_rotor_1k/K.txt", base + "/engineering/generator_rotor_1k/K.bin"},
            {base + "/engineering/plate_10k/M.txt", base + "/engineering/plate_10k/M.bin"},
            {base + "/engineering/plate_10k/C.txt", base + "/engineering/plate_10k/C.bin"},
            {base + "/engineering/plate_10k/K.txt", base + "/engineering/plate_10k/K.bin"},
            {base + "/engineering/turbine_560k/M1.txt", base + "/engineering/turbine_560k/M.bin"},
            {base + "/engineering/turbine_560k/C1.txt", base + "/engineering/turbine_560k/C.bin"},
            {base + "/engineering/turbine_560k/K1.txt", base + "/engineering/turbine_560k/K.bin"},
            {base + "/engineering/vibrating_screen_780k/M.txt", base + "/engineering/vibrating_screen_780k/M.bin"},
            {base + "/engineering/vibrating_screen_780k/C.txt", base + "/engineering/vibrating_screen_780k/C.bin"},
            {base + "/engineering/vibrating_screen_780k/K.txt", base + "/engineering/vibrating_screen_780k/K.bin"},
        };
    }
}

#endif // BINARY_CONVERT_LIST_H
