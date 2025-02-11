#include "BoostSpells.h"

uint32 Spells[12][350] =
    {
        {}, // 0 -
        {
            // 1 - Warrior
            107, 3127, 3018,
            6673, 2457, 78, 100, 772, 6343, 34428, 1715, 284, 2687, 71, 6546, 7386, 355,
            5242, 7384, 72, 1160, 6572, 285, 694, 2565, 676, 8198, 845, 6547, 20230,
            12678, 6192, 5246, 6190, 5308, 1608, 6574, 1161, 6178, 871, 8204, 2458,
            7369, 20252, 6548, 1464, 11549, 18499, 20658, 11564, 11554, 7379, 1680,
            6552, 8820, 8205, 11608, 20660, 11565, 11572, 23922, 11550, 11555, 11600,
            11578, 11604, 20661, 11566, 23923, 11580, 11609, 1719, 11573, 11551, 11556,
            11601, 23924, 11605, 20662, 11567, 11581, 25289, 20569, 25286, 11574, 25288,
            23925, 25241, 25202, 25269, 23920, 25234, 29707, 25258, 25264, 25231, 469,
            25208, 2048, 25242, 25203, 25236, 30324, 3411, 30357, 30356, 46845, 64382,
            47519, 47449, 47470, 47501, 47439, 47474, 55694, 47487, 47450, 47465, 47520,
            47436, 47502, 47437, 47475, 47440, 47471, 57755, 57823, 47488},
        {// 2 - Paladin
         // Missing:
         // 356110, 356112, 53736, 348704, 31801 (Blood/Judgment/Seal of corruption, Seal of vengeance) (faction based)
         // Level 20 mounts: 34769 / 13819 (faction based)
         // Level 40 mounts: 23214 / 34767 (faction based)
         107, 3127, 66907, 66906,
         465, 54968, 635, 20154, 21084, 19740, 20271, 498, 639, 853, 1152, 10290, 1022,
         633, 19834, 53408, 7328, 19742, 647, 31789, 62124, 7294, 25780, 1044, 20217,
         26573, 643, 879, 19750, 5502, 19835, 19746, 1026, 20164, 19850,
         5588, 5599, 10322, 10326, 19939, 1038, 10298, 5614, 53407, 19876, 20116, 10291,
         19752, 1042, 2800, 20165, 19836, 19888, 19852, 642, 19940, 5615, 19891, 10324,
         10299, 10278, 3472, 20166, 20922, 1032, 5589, 19895, 19837, 4987,
         19941, 19853, 10312, 19897, 24275, 6940, 10328, 10300, 19899, 20772, 20923,
         10292, 19942, 2812, 10310, 19838, 10313, 25782, 24274, 19896, 19854, 25894,
         10308, 10329, 19898, 10301, 19943, 25291, 25290, 20924, 10293, 10314, 19900,
         25898, 25916, 25899, 25918, 24239, 25292, 10318, 20773, 32223, 27135, 27151,
         27142, 27143, 27137, 27150, 27138, 27152,
         27180, 27139, 27154, 31884, 27140, 27173, 27149, 27153, 27141, 27136, 48935,
         54428, 48937, 48816, 48949, 48931, 48800, 48933, 48941, 48784, 48805, 48818,
         48781, 53600, 54043, 48943, 48936, 48945, 48938, 48947, 48817, 48788, 48932,
         48942, 48801, 48785, 48934, 48950, 48819, 48806, 48782, 53601, 61411},
        {// 3 - Hunter
         3127,
         75, 2973, 1494, 13163, 1978, 3044, 1130, 5116, 14260, 13165, 883, 2641, 6991,
         982, 13549, 1515, 19883, 14281, 20736, 136, 2974, 6197, 1002, 1513, 5118,
         13795, 1495, 14261, 14318, 2643, 13550, 19884, 14282, 34074, 781, 1499, 3111,
         14323, 3043, 1462, 14262, 19885, 14302, 3045, 13551, 19880, 14283, 14319,
         13809, 3661, 13161, 5384, 14269, 14288, 14326, 1543, 14263, 19878, 13813,
         13552, 14284, 14303, 3662, 3034, 14320, 13159, 14310, 14324, 14264, 19882,
         1510, 14289, 13553, 14285, 14316, 13542, 14270, 20043, 14304, 14327, 14321,
         14265, 13554, 56641, 19879, 14294, 14286, 13543, 14317, 14290, 20190, 14305,
         14266, 14322, 14325, 14271, 13555, 14295, 14287, 25296, 19263, 14311, 13544,
         25294, 25295, 19801, 27025, 34120, 27014, 27023, 34026, 27021, 27016, 27022,
         27044, 27045, 27046, 34600, 27019, 34477, 36916, 49066, 53351, 48995, 49051,
         49055, 49044, 49000, 61846, 48989, 49047, 58431, 61005, 53271, 49071, 53338,
         49067, 48996, 49052, 49056, 49045, 49001, 61847, 62757, 60192, 61006, 48990,
         53339, 49048, 58434},
        {// 4 - Rogue
         3127, 3018, 2764,
         2098, 1804, 1752, 1784, 53, 921, 1776, 1757, 5277, 6760, 6770, 5171, 2983,
         2589, 1766, 8647, 703, 1758, 6761, 1966, 8676, 2590, 51722, 1943, 1725, 8631,
         1759, 1856, 2836, 6762, 8724, 1833, 2591, 6768, 8639, 2070, 1842, 8632, 408,
         1760, 8623, 8725, 2094, 8696, 8721, 8640, 8633, 8621, 8624, 8637, 1860, 11267,
         6774, 1857, 11279, 11273, 11289, 11293, 11299, 11297, 11268, 26669, 8643,
         11280, 11303, 11274, 11290, 11294, 11300, 11269, 11305, 11281, 25300, 31016,
         25302, 11275, 26839, 32645, 26861, 26889, 26679, 26865, 27448, 27441, 31224,
         26863, 26867, 32684, 48689, 48673, 26884, 5938, 26862, 51724, 48658, 48667,
         48656, 57992, 48671, 48690, 48675, 57934, 48674, 48637, 48659, 48668, 48672,
         48691, 48657, 57993, 51723, 48676, 48638},
        {// 5 - Priest
         5019,
         2050, 1243, 585, 2052, 589, 17, 591, 586, 139, 2053, 8092, 2006, 594, 588,
         1244, 592, 528, 8122, 6074, 598, 2054, 8102, 527, 600, 970, 70772, 2944,
         6346, 2061, 14914, 15237, 7128, 453, 6075, 9484, 2055, 8103, 2096, 2010,
         984, 15262, 8129, 1245, 3747, 9472, 6076, 992, 19276, 6063, 15430, 8104,
         8124, 14752, 15263, 602, 605, 6065, 596, 976, 1004, 552, 9473, 6077, 6064,
         1706, 8105, 10880, 2767, 19277, 988, 15264, 15431, 2791, 6066, 9474, 6078,
         6060, 14818, 2060, 1006, 8106, 996, 9485, 15265, 10898, 10888, 10957, 10892,
         19278, 10915, 27799, 10909, 10927, 10963, 10945, 10881, 10933, 15266, 10937,
         10899, 21562, 14819, 10916, 10951, 10960, 10928, 10893, 19279, 10964, 27800,
         10946, 15267, 10900, 10934, 10917, 27683, 10890, 10929, 10958, 10965, 10947,
         20770, 10894, 19280, 27841, 25314, 15261, 27801, 10952, 10938, 10901, 21564,
         10961, 25316, 27681, 25315, 10955, 25233, 25363, 32379, 25210, 25372, 32546,
         25217, 25221, 25367, 25384, 34433, 25235, 25467, 25213, 25331, 25308, 33076,
         25435, 25433, 25431, 25375, 25364, 25312, 32375, 25389, 25218, 25392, 39374,
         32999, 25222, 32996, 25368, 48040, 48119, 48134, 48299, 48070, 48062, 48126,
         48112, 48122, 48077, 48045, 48065, 48067, 48157, 48124, 48072, 48169, 48168,
         48170, 48120, 48063, 48135, 48171, 48300, 48071, 48127, 48113, 48123, 64843,
         48073, 48078, 64901, 64904, 53023, 48161, 48066, 48162, 48074, 48068, 48158,
         48125},
        {// 6 - Death knight
         // Missing: spells < lvl 56
         3127,
         49998, 50842, 46584, 48263, 47528, 54447, 53342, 48721, 45524, 49926, 47476,
         43265, 49917, 53331, 49896, 49020, 3714, 49892, 62901, 48792, 49999, 54446,
         53323, 49927, 45529, 56222, 57330, 49918, 49939, 48743, 49936, 49903, 51423,
         56815, 48707, 49893, 62902, 49928, 45463, 49919, 53344, 62158, 48265, 49940,
         61999, 49937, 49904, 51424, 49929, 49923, 47568, 57623, 49920, 49894, 62903,
         49941, 49909, 51425, 42650, 49930, 49938, 49895, 62904, 49924, 49921},
        {// 7 - Shaman
         // Missing: Bloodlust (faction based) 2825 / 32182
         107,
         331, 403, 8017, 8042, 8071, 2484, 332, 8044, 529, 324, 8018, 5730, 8050,
         8024, 3599, 8075, 2008, 1535, 8349, 547, 370, 8045, 548, 8154, 526, 2645,
         325, 8019, 57994, 8052, 8027, 913, 6390, 8143, 8056, 8033, 5394, 8004, 915,
         6363, 52127, 8498, 8502, 131, 20609, 8046, 8181, 939, 905, 10399, 8155, 8160,
         6196, 8030, 943, 8190, 5675, 8184, 8053, 8227, 8038, 8008, 6391, 52129, 546,
         556, 66842, 51730, 8177, 6375, 10595, 20608, 6364, 36936, 8232, 421, 8499,
         8503, 959, 6041, 945, 8012, 8512, 8058, 6495, 10406, 52131, 20610, 10412,
         16339, 8010, 10585, 10495, 8170, 8249, 10478, 10456, 10391, 6392, 8161, 66843,
         1064, 930, 51988, 10447, 6377, 8005, 8134, 6365, 8235, 52134, 11306, 11314,
         10537, 10466, 10392, 10600, 10407, 10622, 16341, 10472, 10586, 10496, 20776,
         2860, 10413, 10526, 16355, 10395, 10431, 10427, 52136, 66844, 51991, 10462,
         15207, 10437, 10486, 11307, 11315, 10448, 10467, 10442, 10623, 10479, 10408,
         52138, 10605, 16342, 10396, 15208, 10432, 10587, 10497, 10538, 16387, 10473,
         16356, 10428, 20777, 10414, 51992, 29228, 10463, 25357, 10468, 10601, 10438,
         25361, 16362, 25422, 25535, 25546, 25448, 24398, 25439, 25391, 25469, 25508,
         25489, 3738, 25552, 25570, 25528, 2062, 25500, 25420, 25557, 25560, 25449, 25525,
         25423, 2894, 25563, 25464, 25505, 25590, 25454, 25567, 25574, 25533, 33736,
         25442, 51993, 25537, 25547, 25457, 25396, 25472, 25509, 58649, 58785, 58794,
         58755, 58771, 58699, 58580, 58801, 49275, 49235, 49237, 58731, 58751, 55458, 49270,
         49230, 61649, 61650, 58737, 49232, 58652, 58741, 49272, 51505, 49280, 58746, 58703,
         58581, 57622, 58789, 58795, 58756, 58773, 57960, 58803, 49276, 49236, 58734, 58582,
         58753, 49231, 49238, 49277, 55459, 49271, 51994, 61654, 61657, 58739, 49233, 58656,
         58790, 58745, 58796, 58757, 49273, 51514, 60043, 49281, 58774, 58749, 58704, 58643,
         58804},
        {// 8 - Mage
         // Missing: Portals & teleport
         5019,
         1459, 133, 168, 5504, 116, 587, 2136, 143, 5143, 205, 118, 5505, 7300, 122,
         597, 604, 145, 130, 1449, 1460, 2137, 837, 5144, 2120, 1008, 3140, 475, 1953,
         10, 5506, 12051, 543, 7301, 7322, 1463, 12824, 8437, 990, 2138, 6143, 2948,
         5145, 2139, 8450, 8400, 2121, 120, 865, 8406,
         1461, 6141, 759, 8494, 8444, 8455, 8438, 6127, 8412, 8457, 8401, 7302, 45438,
         8416, 6129, 8422, 8461, 8407, 8492, 6117, 8445, 8427, 8451, 8402, 8495,
         8439, 3552, 8413, 8408, 8417, 10138, 8458, 8423,
         6131, 7320, 12825, 8446, 10169, 10156,
         10159, 10144, 10148, 8462, 10185, 10179, 10191, 10201, 10197, 22782, 10205, 10211,
         10053, 10173, 10149, 10215, 10160, 10139, 10223, 10180, 10219, 70909,
         10186, 10145, 10177, 10192, 10206, 10170, 10202, 10199, 10150, 10230, 23028, 10157,
         10212, 10216, 10181, 10161, 10054, 22783, 10207, 25345, 10187, 28612, 10140, 10174,
         10225, 10151, 25306, 28609, 25304, 10220, 10193, 12826, 28271, 28272, 61305, 61721,
         61780, 27078, 27080, 30482, 27130, 27075, 27071, 30451, 27086, 27087,
         37420, 27073, 27070, 30455, 33944, 27088, 27085, 27101, 66, 27131,
         33946, 38699, 27128, 27072, 27124, 27125, 27127, 27082, 27126, 38704, 33717, 27090,
         27079, 38692, 32796, 38697, 43987, 27074, 30449, 42894, 43023, 43045, 53140, 42930,
         42925, 42913, 43019, 42858, 42939, 42872, 42832, 53142, 42843, 42955, 42917, 42841,
         44614, 42896, 42920, 43015, 43017, 42985, 43010, 42833, 42914, 42859, 42846, 42931,
         42926, 43012, 42842, 43008, 43024, 43020, 43046, 42897, 43002, 42921, 42995, 42940,
         42956, 61316, 61024, 42873, 47610, 55342, 58659},
        {// 9 - Warlock
         5019,
         687, 348, 686, 688, 172, 702, 1454, 695, 980, 5782, 6201, 696, 1120, 707,
         697, 1108, 755, 705, 6222, 689, 1455, 5697, 693, 1014, 5676, 706, 5784,
         3698, 1094, 5740, 698, 1088, 713, 712, 6202, 6205, 699, 126, 6223, 5138,
         8288, 5500, 1714, 132, 1456, 17919, 710, 6366, 6217, 3699, 1106, 20752,
         1086, 709, 1949, 2941, 1098, 691, 1490, 7646, 6213, 6229, 7648, 5699, 6219,
         17920, 17951, 2362, 3700, 11687, 7641, 11711, 7651, 8289, 20755, 11733,
         23161, 5484, 11665, 11707, 6789, 11683, 17921, 11739, 11671, 11693, 11659,
         11725, 17952, 11729, 11721, 11699, 11688, 11677, 18647, 17727, 11712, 6353,
         20756, 11719, 17925, 11734, 11667, 1122, 17922, 11708, 11675, 11694, 11660,
         11740, 11672, 11700, 11684, 17928, 17953, 6215, 11689, 17924, 11730, 11713,
         17926, 11678, 17923, 11726, 25311, 20757, 17728, 603, 11722, 11735, 54785,
         11695, 11668, 25309, 50589, 18540, 11661, 25307, 50581, 28610, 27224, 27219,
         28176, 29722, 27211, 27216, 27210, 27250, 28172, 29858, 27218, 27217, 27259,
         27230, 27223, 27213, 27222, 29893, 27228, 30909, 27220, 28189, 27215, 27212,
         27209, 27238, 30910, 27260, 32231, 30459, 27243, 30545, 47812, 50511, 47886,
         47819, 47890, 61191, 47871, 47863, 47859, 60219, 47892, 47837, 47814, 47808,
         47810, 47835, 47897, 47824, 47884, 47793, 47856, 47813, 47855, 47888, 47865,
         47860, 47857, 47823, 47891, 47878, 47864, 47893, 47820, 47815, 47809, 60220,
         47867, 47889, 48018, 48020, 47811, 47838, 57946, 58887, 47836, 61290, 47825},
        {}, // 10 -
        {
            // 11 - Druid
            5185, 1126, 5176, 8921, 774, 467, 5177, 339, 5186, 5487, 99, 6795, 5232,
            6807, 8924, 16689, 1058, 18960, 5229, 8936, 50769, 5211, 8946, 5187, 782,
            5178, 1066, 8925, 1430, 779, 783, 1062, 770, 16857, 2637, 6808, 16810,
            8938, 768, 1082, 1735, 16979, 49376, 5188, 6756, 5215, 20484, 1079, 2912,
            8926, 2090, 5221, 2908, 5179, 1822, 8939, 2782, 50768, 780, 1075, 5217,
            2893, 1850, 5189, 6809, 8949, 5209, 3029, 8998, 5195, 8927, 16811, 2091,
            9492, 6798, 5234, 20739, 8940, 6800, 740, 44203, 5180, 9490, 22568, 6778,
            6785, 5225, 8972, 8928, 1823, 3627, 8950, 769, 8914, 22842, 9005, 8941, 50767,
            9493, 6793, 5201, 5196, 8903, 18657, 16812, 8992, 8955, 6780, 9000, 9634, 20719,
            22827, 16914, 29166, 8907, 8929, 20742, 8910, 62600, 8918, 44205, 9747, 9745,
            6787, 9750, 8951, 22812, 9758, 1824, 9752, 9754, 9756, 8983, 9821, 9833, 9823,
            9839, 9829, 8905, 9849, 9852, 22828, 16813, 9856, 50766, 9845, 21849, 9888,
            17401, 33878, 33876, 9884, 9880, 9866, 20747, 9875, 9862, 44206, 33891, 9892,
            9898, 9834, 9840, 9894, 9904, 9857, 9830, 9901, 9908, 9910, 9912, 22829, 9889,
            9827, 9850, 9853, 18658, 33986, 33982, 9881, 9835, 17329, 9867, 9841, 9876,
            31709, 31018, 33943, 21850, 25297, 17402, 9885, 20748, 9858, 25299, 50765,
            9896, 25298, 9846, 9863, 44207, 27001, 26984, 26998, 26978, 22570, 24248,
            26987, 26981, 33763, 27003, 26997, 26992, 33357, 26980, 33745, 27006, 27005,
            27000, 26996, 27008, 26986, 26989, 33987, 33983, 27009, 27004, 26979, 26994,
            26982, 50764, 26985, 33786, 26991, 27012, 26990, 26988, 27002, 26995, 40120,
            26983, 44208, 48559, 48442, 49799, 62078, 50212, 48576, 48450, 48573, 48464,
            48561, 48569, 48567, 48479, 48578, 48377, 49802, 53307, 48459, 48563, 48565,
            48462, 48440, 52610, 48571, 48446, 48575, 48560, 49803, 48443, 48562, 53308,
            48577, 53312, 48574, 48465, 48570, 48378, 48480, 48579, 48477, 50213, 48461,
            48470, 48467, 48568, 48451, 48564, 48566, 48469, 48463, 50464, 48441, 50763,
            49800, 48572, 48447},
};

class BoostSpells
{
public:
  static void LearnSpells(Player *player)
  {
    uint32 playerClass = player->getClass();
    for (int i = 0; i < 350; i++)
    {
      if (Spells[playerClass][i] == 0)
      {
        break;
      }
      player->learnSpell(Spells[playerClass][i], false);
    }

    // Missing spells
    if (player->getClass() == CLASS_MAGE)
    {
      if (player->GetTeamId() == TEAM_ALLIANCE)
      {
        player->learnSpell(32271, false);
        player->learnSpell(49359, false);
        player->learnSpell(3565, false);
        player->learnSpell(33690, false);
        player->learnSpell(3562, false);
        player->learnSpell(3561, false);
        player->learnSpell(53140, false);
        player->learnSpell(53142, false);
        player->learnSpell(10059, false);
        player->learnSpell(11419, false);
        player->learnSpell(32266, false);
        player->learnSpell(11416, false);
        player->learnSpell(33691, false);
        player->learnSpell(49360, false);
      }
      else
      {
        player->learnSpell(3567, false);
        player->learnSpell(35715, false);
        player->learnSpell(3566, false);
        player->learnSpell(49358, false);
        player->learnSpell(32272, false);
        player->learnSpell(3563, false);
        player->learnSpell(53140, false);
        player->learnSpell(53142, false);
        player->learnSpell(11417, false);
        player->learnSpell(35717, false);
        player->learnSpell(32267, false);
        player->learnSpell(49361, false);
        player->learnSpell(11420, false);
        player->learnSpell(11418, false);
      }
    }
    else if (player->getClass() == CLASS_SHAMAN)
    {
      if (player->GetTeamId() == TEAM_ALLIANCE)
      {
        player->learnSpell(32182, false);
      }
      else
      {
        player->learnSpell(2825, false);
      }
    }
    else if (player->getClass() == CLASS_PALADIN)
    {
      if (player->GetTeamId() == TEAM_ALLIANCE)
      {
        player->learnSpell(31801, false);
        player->learnSpell(13819, false);
        player->learnSpell(23214, false);
      }
      else
      {
        player->learnSpell(53736, false);
        player->learnSpell(34769, false);
        player->learnSpell(34767, false);
      }
    }
  }
};