//
// Created by LiMi on 2026/8/28.
//

#include "../Header/_100_Maps_in_CPP_std_map_and_std_unordered_map.h"

#include <cstdint>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>


namespace _100 {
    struct CityRecord {
        std::string Name;
        uint64_t Population;
        double Latitude, Longitude;
    };
}

namespace std {
    using namespace _100;

    template<>
    struct hash<CityRecord> {
        size_t operator()(const CityRecord& key) {
            return hash<std::string>()(key.Name);
        }
    };
}

void _100_Maps_in_CPP_std_map_and_std_unordered_map::main() {
    //MAPS C++
    //你应该听说过map、hash map、hash table或关联数组（associative array)
    //映射允许你定义键（key），用它就能快速查找到对应的值
    //这是因为它们本来就是不同类型的map

    //其中一种是排序map，它的所有元素都保持有序排列
    //另一种unorderedmap则完全不保持元素顺序
    //这个有序map（就是普通的map）底层采用自平衡二叉搜索树实现，通常是红黑树结构
    //因为是树结构（如二叉树），元素自然有序排列
    //而无序映射（unorderedmap）则采用哈希表结构 通过生成的索引就能定位数值所在的存储桶
    //这种结构是完全无序的，实际运行速度通常比map要快不少
    //根据经验，我建议尽量使用unordered_map 因为unordered_map通常比map更快
    using namespace _100;

    std::vector<CityRecord> cities;

    cities.emplace_back("Melbourne", 50000000000, 2.4, 9.4);
    cities.emplace_back("Lol-toen", 50000000000, 2.4, 9.4);
    cities.emplace_back("Berlin", 50000000000, 2.4, 9.4);
    cities.emplace_back("Paris", 50000000000, 2.4, 9.4);
    cities.emplace_back("London", 50000000000, 2.4, 9.4);

    //首先，逐个搜索所有城市确实很费劲 再用二分查找法缩小范围
    for (const auto& city: cities) {
        if (city.Name == "Melbourne") {
            city.Population;
            break;
        }
    }

    //===============================================================================
    std::pmr::unordered_map<std::string, CityRecord> citymap;
    citymap["Melbourne"] = CityRecord{"Melbourne", 50000000000, 2.4, 9.4};
    citymap["Lol-toen"] = CityRecord{"Lol-toen", 50000000000, 2.4, 9.4};
    //citymap["Berlin"] = CityRecord{"Berlin", 50000000000, 2.4, 9.4};
    citymap["Paris"] = CityRecord{"Paris", 50000000000, 2.4, 9.4};
    citymap["London"] = CityRecord{"London", 50000000000, 2.4, 9.4};

    //获取
    //CityRecord& berry = citymap["Berry"];

    const auto& cities2 = citymap;
    if (cities2.find("Berlin") != cities2.end()) {
        //const CityRecord& berlinData = cities2.at["Berlin"];
        /*berlinData.Name = "Berlin";
        berlinData.Name = "Berlin";
        berlinData.Name = "Berlin";*/
    }


    /*CityRecord berlinData1;
    berlinData1.Name = "Berlin";
    berlinData1.Population = 5;
    citymap["Berlin"] = berlinData1;*/

    //================================================================

    for (auto& kv: citymap) {
        auto& name = kv.first;
        CityRecord& city =kv.second;
    }
    std::unordered_map<CityRecord, uint32_t> foundedMap;
    //foundedMap[CityRecord{"Melbourne", 50000000000, 2.4, 9.4}] = 1850;
}
