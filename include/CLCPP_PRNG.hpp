#ifndef CLCPP_PRNG_HPP
#define CLCPP_PRNG_HPP
#include <map>
#include <string>
#include <algorithm>

namespace CLCPP
{
const char* PRNG_INCLUDE_DIR = "/home/arch/Documents/PRNG/include/";
const char* RANDOMCL_INCLUDE_DIR = "/home/arch/Documents/PRNG/build/_deps/randomcl_repo-src/generators/";
const char* PRNG_INCLUDE = "-I /home/arch/Documents/PRNG/include/ -I /home/arch/Documents/PRNG/build/_deps/randomcl_repo-src/generators/";


enum PRNG_TYPE
{
    PRNG_TYPE_ISAAC,
    PRNG_TYPE_KISS99,
    PRNG_TYPE_LCG6432,
    PRNG_TYPE_LFIB,
    PRNG_TYPE_MRG31K3P,
    PRNG_TYPE_MRG63K3A,
    PRNG_TYPE_MSWS,
    PRNG_TYPE_MT19937,
    PRNG_TYPE_MWC64X,
    PRNG_TYPE_PCG6432,
    PRNG_TYPE_PHILOX2X32_10,
    PRNG_TYPE_RAN2,
    PRNG_TYPE_TINYMT,
    PRNG_TYPE_TINYMT32,
    PRNG_TYPE_TINYMT64,
    PRNG_TYPE_TYCHE,
    PRNG_TYPE_WELL512,
    PRNG_TYPE_XORSHIFT6432STAR
};

const std::map <PRNG_TYPE, std::string> PRNG_strmap = {{PRNG_TYPE_ISAAC,"isaac"},
    {PRNG_TYPE_KISS99,"kiss99"},
    {PRNG_TYPE_LCG6432,"lcg6432"},
    {PRNG_TYPE_LFIB,"lfib"},
    {PRNG_TYPE_MRG31K3P,"mrg31k3p"},
    {PRNG_TYPE_MRG63K3A,"mrg63k3a"},
    {PRNG_TYPE_MSWS,"msws"},
    {PRNG_TYPE_MT19937,"mt19937"},
    {PRNG_TYPE_MWC64X,"mwc64x"},
    {PRNG_TYPE_PCG6432,"pcg6432"},
    {PRNG_TYPE_PHILOX2X32_10,"philox2x32_10"},
    {PRNG_TYPE_RAN2,"ran2"},
    {PRNG_TYPE_TINYMT32,"tinymt32"},
    {PRNG_TYPE_TINYMT64,"tinymt64"},
    {PRNG_TYPE_TYCHE,"tyche"},
    {PRNG_TYPE_WELL512,"well512"},
    {PRNG_TYPE_XORSHIFT6432STAR,"xorshift6432star"}};

const std::map <PRNG_TYPE, std::string> PRNG_class_strmap = {{PRNG_TYPE_ISAAC,"PRNG_ISAAC"},
    {PRNG_TYPE_KISS99,"PRNG_KISS99"},
    {PRNG_TYPE_LCG6432,"PRNG_LCG6432"},
    {PRNG_TYPE_LFIB,"PRNG_LFIB"},
    {PRNG_TYPE_MRG31K3P,"PRNG_MRG31K3P"},
    {PRNG_TYPE_MRG63K3A,"PRNG_MRG63K3A"},
    {PRNG_TYPE_MSWS,"PRNG_MSWS"},
    {PRNG_TYPE_MT19937,"PRNG_MT19937"},
    {PRNG_TYPE_MWC64X,"PRNG_MWC64X"},
    {PRNG_TYPE_PCG6432,"pcg6432"},
    {PRNG_TYPE_PHILOX2X32_10,"PRNG_PHILOX2X32_10"},
    {PRNG_TYPE_RAN2,"PRNG_RAN2"},
    {PRNG_TYPE_TINYMT32,"PRNG_TINYMT32"},
    {PRNG_TYPE_TINYMT64,"PRNG_TINYMT64"},
    {PRNG_TYPE_TYCHE,"PRNG_TYCHE"},
    {PRNG_TYPE_WELL512,"PRNG_WELL512"},
    {PRNG_TYPE_XORSHIFT6432STAR,"PRNG_XORSHIFT6432STAR"}};

std::string configure_generator(PRNG_TYPE generator_type)
{
    std::string generator_name = PRNG_strmap.at(generator_type);
    std::string generator_name_upper = generator_name;
    for (auto& c: generator_name_upper) c = std::toupper(c);

    std::string PRNG_state = "#define PRNG_STATE " + generator_name + "_state\n";

    std::string PRNG_seed_fn;
    std::string PRNG_float_fn;
    std::string PRNG_include_file = "#include <" + generator_name + ".cl>\n";
    PRNG_seed_fn = "#define PRNG_SEED_FN " + generator_name + "_seed\n";
    PRNG_float_fn = "#define PRNG_FLOAT_FN " + generator_name + "_float\n";
    return PRNG_state + PRNG_seed_fn + PRNG_float_fn + PRNG_include_file + "#include <Distributions.cl>\n";
}
}
#endif
