#ifndef ORDER_INTERPRETER_H_VAJK20040620
#define ORDER_INTERPRETER_H_VAJK20040620

// (C) Copyright Vesa Karvonen 2004.
//
//    Distributed under the Boost Software License, Version 1.0.

#ifndef CHAOS_PP_VARIADICS
#define CHAOS_PP_VARIADICS 1
#endif

#if 1 != CHAOS_PP_VARIADICS
#error Order requires variadics.
#endif

#define ORDER_PP_VERIFY_VARIADICS(...)

#include "order/cm.h"
#include "order/def.h"
#include "order/eval.h"
#include "order/output.h"
#include "order/pm.h"
#include "order/prelude.h"
#include "order/util.h"

#define ORDER_PP ORDER_PP_IS_ACTIVE(0)(,ORDER_PP_FIND,ORDER_PP_EVAL)(0)

#define ORDER_PP_FIND(i) ORDER_PP_FX(,ORDER_PP_EVAL,(ORDER_PP_FIND_GT_0()))
#define ORDER_PP_EVAL(i) ORDER_PP_EVAL_##i

#define ORDER_PP_IS_ACTIVE(i) ORDER_PP_TEST(ORDER_PP_IF_,ORDER_PP_SCAN_##i(,,),8false,8true)

/*
(let ((max 126))
  (defun bin-search (l h)
    (unless (= l h)
      (let ((m (+ l (/ (1- (- h l)) 2))))
        (bin-search l m)
        (if (= l m)
            (insert "#define ORDER_PP_FIND_IN_" (number-to-string l) "_" (number-to-string h) "() ORDER_PP_IS_ACTIVE(" (number-to-string m) ")(," (number-to-string h) "," (number-to-string l) ")\n")
          (insert "#define ORDER_PP_FIND_IN_" (number-to-string l) "_" (number-to-string h) "() ORDER_PP_IS_ACTIVE(" (number-to-string m) ")(,ORDER_PP_FIND_IN_" (number-to-string l) "_" (number-to-string m) ",ORDER_PP_FIND_IN_" (number-to-string (1+ m)) "_" (number-to-string h) ")()\n"))
        (bin-search (1+ m) h))))
  (defun search-gt (i)
    (when (< i max)
      (let ((l (1+ i))
            (h (* 2 (1+ i))))
        (insert "#define ORDER_PP_FIND_GT_" (number-to-string i) "() ORDER_PP_IS_ACTIVE(" (number-to-string h) ")" "(,ORDER_PP_FIND_GT_" (number-to-string h) ",ORDER_PP_FIND_IN_" (number-to-string l) "_" (number-to-string h) ")()\n")
        (bin-search l h)
        (search-gt h))))
  (search-gt 0))
*/

#define ORDER_PP_FIND_GT_0() ORDER_PP_IS_ACTIVE(2)(,ORDER_PP_FIND_GT_2,ORDER_PP_FIND_IN_1_2)()
#define ORDER_PP_FIND_IN_1_2() ORDER_PP_IS_ACTIVE(1)(,2,1)
#define ORDER_PP_FIND_GT_2() ORDER_PP_IS_ACTIVE(6)(,ORDER_PP_FIND_GT_6,ORDER_PP_FIND_IN_3_6)()
#define ORDER_PP_FIND_IN_3_4() ORDER_PP_IS_ACTIVE(3)(,4,3)
#define ORDER_PP_FIND_IN_3_6() ORDER_PP_IS_ACTIVE(4)(,ORDER_PP_FIND_IN_3_4,ORDER_PP_FIND_IN_5_6)()
#define ORDER_PP_FIND_IN_5_6() ORDER_PP_IS_ACTIVE(5)(,6,5)
#define ORDER_PP_FIND_GT_6() ORDER_PP_IS_ACTIVE(14)(,ORDER_PP_FIND_GT_14,ORDER_PP_FIND_IN_7_14)()
#define ORDER_PP_FIND_IN_7_8() ORDER_PP_IS_ACTIVE(7)(,8,7)
#define ORDER_PP_FIND_IN_7_10() ORDER_PP_IS_ACTIVE(8)(,ORDER_PP_FIND_IN_7_8,ORDER_PP_FIND_IN_9_10)()
#define ORDER_PP_FIND_IN_9_10() ORDER_PP_IS_ACTIVE(9)(,10,9)
#define ORDER_PP_FIND_IN_7_14() ORDER_PP_IS_ACTIVE(10)(,ORDER_PP_FIND_IN_7_10,ORDER_PP_FIND_IN_11_14)()
#define ORDER_PP_FIND_IN_11_12() ORDER_PP_IS_ACTIVE(11)(,12,11)
#define ORDER_PP_FIND_IN_11_14() ORDER_PP_IS_ACTIVE(12)(,ORDER_PP_FIND_IN_11_12,ORDER_PP_FIND_IN_13_14)()
#define ORDER_PP_FIND_IN_13_14() ORDER_PP_IS_ACTIVE(13)(,14,13)
#define ORDER_PP_FIND_GT_14() ORDER_PP_IS_ACTIVE(30)(,ORDER_PP_FIND_GT_30,ORDER_PP_FIND_IN_15_30)()
#define ORDER_PP_FIND_IN_15_16() ORDER_PP_IS_ACTIVE(15)(,16,15)
#define ORDER_PP_FIND_IN_15_18() ORDER_PP_IS_ACTIVE(16)(,ORDER_PP_FIND_IN_15_16,ORDER_PP_FIND_IN_17_18)()
#define ORDER_PP_FIND_IN_17_18() ORDER_PP_IS_ACTIVE(17)(,18,17)
#define ORDER_PP_FIND_IN_15_22() ORDER_PP_IS_ACTIVE(18)(,ORDER_PP_FIND_IN_15_18,ORDER_PP_FIND_IN_19_22)()
#define ORDER_PP_FIND_IN_19_20() ORDER_PP_IS_ACTIVE(19)(,20,19)
#define ORDER_PP_FIND_IN_19_22() ORDER_PP_IS_ACTIVE(20)(,ORDER_PP_FIND_IN_19_20,ORDER_PP_FIND_IN_21_22)()
#define ORDER_PP_FIND_IN_21_22() ORDER_PP_IS_ACTIVE(21)(,22,21)
#define ORDER_PP_FIND_IN_15_30() ORDER_PP_IS_ACTIVE(22)(,ORDER_PP_FIND_IN_15_22,ORDER_PP_FIND_IN_23_30)()
#define ORDER_PP_FIND_IN_23_24() ORDER_PP_IS_ACTIVE(23)(,24,23)
#define ORDER_PP_FIND_IN_23_26() ORDER_PP_IS_ACTIVE(24)(,ORDER_PP_FIND_IN_23_24,ORDER_PP_FIND_IN_25_26)()
#define ORDER_PP_FIND_IN_25_26() ORDER_PP_IS_ACTIVE(25)(,26,25)
#define ORDER_PP_FIND_IN_23_30() ORDER_PP_IS_ACTIVE(26)(,ORDER_PP_FIND_IN_23_26,ORDER_PP_FIND_IN_27_30)()
#define ORDER_PP_FIND_IN_27_28() ORDER_PP_IS_ACTIVE(27)(,28,27)
#define ORDER_PP_FIND_IN_27_30() ORDER_PP_IS_ACTIVE(28)(,ORDER_PP_FIND_IN_27_28,ORDER_PP_FIND_IN_29_30)()
#define ORDER_PP_FIND_IN_29_30() ORDER_PP_IS_ACTIVE(29)(,30,29)
#define ORDER_PP_FIND_GT_30() ORDER_PP_IS_ACTIVE(62)(,ORDER_PP_FIND_GT_62,ORDER_PP_FIND_IN_31_62)()
#define ORDER_PP_FIND_IN_31_32() ORDER_PP_IS_ACTIVE(31)(,32,31)
#define ORDER_PP_FIND_IN_31_34() ORDER_PP_IS_ACTIVE(32)(,ORDER_PP_FIND_IN_31_32,ORDER_PP_FIND_IN_33_34)()
#define ORDER_PP_FIND_IN_33_34() ORDER_PP_IS_ACTIVE(33)(,34,33)
#define ORDER_PP_FIND_IN_31_38() ORDER_PP_IS_ACTIVE(34)(,ORDER_PP_FIND_IN_31_34,ORDER_PP_FIND_IN_35_38)()
#define ORDER_PP_FIND_IN_35_36() ORDER_PP_IS_ACTIVE(35)(,36,35)
#define ORDER_PP_FIND_IN_35_38() ORDER_PP_IS_ACTIVE(36)(,ORDER_PP_FIND_IN_35_36,ORDER_PP_FIND_IN_37_38)()
#define ORDER_PP_FIND_IN_37_38() ORDER_PP_IS_ACTIVE(37)(,38,37)
#define ORDER_PP_FIND_IN_31_46() ORDER_PP_IS_ACTIVE(38)(,ORDER_PP_FIND_IN_31_38,ORDER_PP_FIND_IN_39_46)()
#define ORDER_PP_FIND_IN_39_40() ORDER_PP_IS_ACTIVE(39)(,40,39)
#define ORDER_PP_FIND_IN_39_42() ORDER_PP_IS_ACTIVE(40)(,ORDER_PP_FIND_IN_39_40,ORDER_PP_FIND_IN_41_42)()
#define ORDER_PP_FIND_IN_41_42() ORDER_PP_IS_ACTIVE(41)(,42,41)
#define ORDER_PP_FIND_IN_39_46() ORDER_PP_IS_ACTIVE(42)(,ORDER_PP_FIND_IN_39_42,ORDER_PP_FIND_IN_43_46)()
#define ORDER_PP_FIND_IN_43_44() ORDER_PP_IS_ACTIVE(43)(,44,43)
#define ORDER_PP_FIND_IN_43_46() ORDER_PP_IS_ACTIVE(44)(,ORDER_PP_FIND_IN_43_44,ORDER_PP_FIND_IN_45_46)()
#define ORDER_PP_FIND_IN_45_46() ORDER_PP_IS_ACTIVE(45)(,46,45)
#define ORDER_PP_FIND_IN_31_62() ORDER_PP_IS_ACTIVE(46)(,ORDER_PP_FIND_IN_31_46,ORDER_PP_FIND_IN_47_62)()
#define ORDER_PP_FIND_IN_47_48() ORDER_PP_IS_ACTIVE(47)(,48,47)
#define ORDER_PP_FIND_IN_47_50() ORDER_PP_IS_ACTIVE(48)(,ORDER_PP_FIND_IN_47_48,ORDER_PP_FIND_IN_49_50)()
#define ORDER_PP_FIND_IN_49_50() ORDER_PP_IS_ACTIVE(49)(,50,49)
#define ORDER_PP_FIND_IN_47_54() ORDER_PP_IS_ACTIVE(50)(,ORDER_PP_FIND_IN_47_50,ORDER_PP_FIND_IN_51_54)()
#define ORDER_PP_FIND_IN_51_52() ORDER_PP_IS_ACTIVE(51)(,52,51)
#define ORDER_PP_FIND_IN_51_54() ORDER_PP_IS_ACTIVE(52)(,ORDER_PP_FIND_IN_51_52,ORDER_PP_FIND_IN_53_54)()
#define ORDER_PP_FIND_IN_53_54() ORDER_PP_IS_ACTIVE(53)(,54,53)
#define ORDER_PP_FIND_IN_47_62() ORDER_PP_IS_ACTIVE(54)(,ORDER_PP_FIND_IN_47_54,ORDER_PP_FIND_IN_55_62)()
#define ORDER_PP_FIND_IN_55_56() ORDER_PP_IS_ACTIVE(55)(,56,55)
#define ORDER_PP_FIND_IN_55_58() ORDER_PP_IS_ACTIVE(56)(,ORDER_PP_FIND_IN_55_56,ORDER_PP_FIND_IN_57_58)()
#define ORDER_PP_FIND_IN_57_58() ORDER_PP_IS_ACTIVE(57)(,58,57)
#define ORDER_PP_FIND_IN_55_62() ORDER_PP_IS_ACTIVE(58)(,ORDER_PP_FIND_IN_55_58,ORDER_PP_FIND_IN_59_62)()
#define ORDER_PP_FIND_IN_59_60() ORDER_PP_IS_ACTIVE(59)(,60,59)
#define ORDER_PP_FIND_IN_59_62() ORDER_PP_IS_ACTIVE(60)(,ORDER_PP_FIND_IN_59_60,ORDER_PP_FIND_IN_61_62)()
#define ORDER_PP_FIND_IN_61_62() ORDER_PP_IS_ACTIVE(61)(,62,61)
#define ORDER_PP_FIND_GT_62() ORDER_PP_IS_ACTIVE(126)(,ORDER_PP_FIND_GT_126,ORDER_PP_FIND_IN_63_126)()
#define ORDER_PP_FIND_IN_63_64() ORDER_PP_IS_ACTIVE(63)(,64,63)
#define ORDER_PP_FIND_IN_63_66() ORDER_PP_IS_ACTIVE(64)(,ORDER_PP_FIND_IN_63_64,ORDER_PP_FIND_IN_65_66)()
#define ORDER_PP_FIND_IN_65_66() ORDER_PP_IS_ACTIVE(65)(,66,65)
#define ORDER_PP_FIND_IN_63_70() ORDER_PP_IS_ACTIVE(66)(,ORDER_PP_FIND_IN_63_66,ORDER_PP_FIND_IN_67_70)()
#define ORDER_PP_FIND_IN_67_68() ORDER_PP_IS_ACTIVE(67)(,68,67)
#define ORDER_PP_FIND_IN_67_70() ORDER_PP_IS_ACTIVE(68)(,ORDER_PP_FIND_IN_67_68,ORDER_PP_FIND_IN_69_70)()
#define ORDER_PP_FIND_IN_69_70() ORDER_PP_IS_ACTIVE(69)(,70,69)
#define ORDER_PP_FIND_IN_63_78() ORDER_PP_IS_ACTIVE(70)(,ORDER_PP_FIND_IN_63_70,ORDER_PP_FIND_IN_71_78)()
#define ORDER_PP_FIND_IN_71_72() ORDER_PP_IS_ACTIVE(71)(,72,71)
#define ORDER_PP_FIND_IN_71_74() ORDER_PP_IS_ACTIVE(72)(,ORDER_PP_FIND_IN_71_72,ORDER_PP_FIND_IN_73_74)()
#define ORDER_PP_FIND_IN_73_74() ORDER_PP_IS_ACTIVE(73)(,74,73)
#define ORDER_PP_FIND_IN_71_78() ORDER_PP_IS_ACTIVE(74)(,ORDER_PP_FIND_IN_71_74,ORDER_PP_FIND_IN_75_78)()
#define ORDER_PP_FIND_IN_75_76() ORDER_PP_IS_ACTIVE(75)(,76,75)
#define ORDER_PP_FIND_IN_75_78() ORDER_PP_IS_ACTIVE(76)(,ORDER_PP_FIND_IN_75_76,ORDER_PP_FIND_IN_77_78)()
#define ORDER_PP_FIND_IN_77_78() ORDER_PP_IS_ACTIVE(77)(,78,77)
#define ORDER_PP_FIND_IN_63_94() ORDER_PP_IS_ACTIVE(78)(,ORDER_PP_FIND_IN_63_78,ORDER_PP_FIND_IN_79_94)()
#define ORDER_PP_FIND_IN_79_80() ORDER_PP_IS_ACTIVE(79)(,80,79)
#define ORDER_PP_FIND_IN_79_82() ORDER_PP_IS_ACTIVE(80)(,ORDER_PP_FIND_IN_79_80,ORDER_PP_FIND_IN_81_82)()
#define ORDER_PP_FIND_IN_81_82() ORDER_PP_IS_ACTIVE(81)(,82,81)
#define ORDER_PP_FIND_IN_79_86() ORDER_PP_IS_ACTIVE(82)(,ORDER_PP_FIND_IN_79_82,ORDER_PP_FIND_IN_83_86)()
#define ORDER_PP_FIND_IN_83_84() ORDER_PP_IS_ACTIVE(83)(,84,83)
#define ORDER_PP_FIND_IN_83_86() ORDER_PP_IS_ACTIVE(84)(,ORDER_PP_FIND_IN_83_84,ORDER_PP_FIND_IN_85_86)()
#define ORDER_PP_FIND_IN_85_86() ORDER_PP_IS_ACTIVE(85)(,86,85)
#define ORDER_PP_FIND_IN_79_94() ORDER_PP_IS_ACTIVE(86)(,ORDER_PP_FIND_IN_79_86,ORDER_PP_FIND_IN_87_94)()
#define ORDER_PP_FIND_IN_87_88() ORDER_PP_IS_ACTIVE(87)(,88,87)
#define ORDER_PP_FIND_IN_87_90() ORDER_PP_IS_ACTIVE(88)(,ORDER_PP_FIND_IN_87_88,ORDER_PP_FIND_IN_89_90)()
#define ORDER_PP_FIND_IN_89_90() ORDER_PP_IS_ACTIVE(89)(,90,89)
#define ORDER_PP_FIND_IN_87_94() ORDER_PP_IS_ACTIVE(90)(,ORDER_PP_FIND_IN_87_90,ORDER_PP_FIND_IN_91_94)()
#define ORDER_PP_FIND_IN_91_92() ORDER_PP_IS_ACTIVE(91)(,92,91)
#define ORDER_PP_FIND_IN_91_94() ORDER_PP_IS_ACTIVE(92)(,ORDER_PP_FIND_IN_91_92,ORDER_PP_FIND_IN_93_94)()
#define ORDER_PP_FIND_IN_93_94() ORDER_PP_IS_ACTIVE(93)(,94,93)
#define ORDER_PP_FIND_IN_63_126() ORDER_PP_IS_ACTIVE(94)(,ORDER_PP_FIND_IN_63_94,ORDER_PP_FIND_IN_95_126)()
#define ORDER_PP_FIND_IN_95_96() ORDER_PP_IS_ACTIVE(95)(,96,95)
#define ORDER_PP_FIND_IN_95_98() ORDER_PP_IS_ACTIVE(96)(,ORDER_PP_FIND_IN_95_96,ORDER_PP_FIND_IN_97_98)()
#define ORDER_PP_FIND_IN_97_98() ORDER_PP_IS_ACTIVE(97)(,98,97)
#define ORDER_PP_FIND_IN_95_102() ORDER_PP_IS_ACTIVE(98)(,ORDER_PP_FIND_IN_95_98,ORDER_PP_FIND_IN_99_102)()
#define ORDER_PP_FIND_IN_99_100() ORDER_PP_IS_ACTIVE(99)(,100,99)
#define ORDER_PP_FIND_IN_99_102() ORDER_PP_IS_ACTIVE(100)(,ORDER_PP_FIND_IN_99_100,ORDER_PP_FIND_IN_101_102)()
#define ORDER_PP_FIND_IN_101_102() ORDER_PP_IS_ACTIVE(101)(,102,101)
#define ORDER_PP_FIND_IN_95_110() ORDER_PP_IS_ACTIVE(102)(,ORDER_PP_FIND_IN_95_102,ORDER_PP_FIND_IN_103_110)()
#define ORDER_PP_FIND_IN_103_104() ORDER_PP_IS_ACTIVE(103)(,104,103)
#define ORDER_PP_FIND_IN_103_106() ORDER_PP_IS_ACTIVE(104)(,ORDER_PP_FIND_IN_103_104,ORDER_PP_FIND_IN_105_106)()
#define ORDER_PP_FIND_IN_105_106() ORDER_PP_IS_ACTIVE(105)(,106,105)
#define ORDER_PP_FIND_IN_103_110() ORDER_PP_IS_ACTIVE(106)(,ORDER_PP_FIND_IN_103_106,ORDER_PP_FIND_IN_107_110)()
#define ORDER_PP_FIND_IN_107_108() ORDER_PP_IS_ACTIVE(107)(,108,107)
#define ORDER_PP_FIND_IN_107_110() ORDER_PP_IS_ACTIVE(108)(,ORDER_PP_FIND_IN_107_108,ORDER_PP_FIND_IN_109_110)()
#define ORDER_PP_FIND_IN_109_110() ORDER_PP_IS_ACTIVE(109)(,110,109)
#define ORDER_PP_FIND_IN_95_126() ORDER_PP_IS_ACTIVE(110)(,ORDER_PP_FIND_IN_95_110,ORDER_PP_FIND_IN_111_126)()
#define ORDER_PP_FIND_IN_111_112() ORDER_PP_IS_ACTIVE(111)(,112,111)
#define ORDER_PP_FIND_IN_111_114() ORDER_PP_IS_ACTIVE(112)(,ORDER_PP_FIND_IN_111_112,ORDER_PP_FIND_IN_113_114)()
#define ORDER_PP_FIND_IN_113_114() ORDER_PP_IS_ACTIVE(113)(,114,113)
#define ORDER_PP_FIND_IN_111_118() ORDER_PP_IS_ACTIVE(114)(,ORDER_PP_FIND_IN_111_114,ORDER_PP_FIND_IN_115_118)()
#define ORDER_PP_FIND_IN_115_116() ORDER_PP_IS_ACTIVE(115)(,116,115)
#define ORDER_PP_FIND_IN_115_118() ORDER_PP_IS_ACTIVE(116)(,ORDER_PP_FIND_IN_115_116,ORDER_PP_FIND_IN_117_118)()
#define ORDER_PP_FIND_IN_117_118() ORDER_PP_IS_ACTIVE(117)(,118,117)
#define ORDER_PP_FIND_IN_111_126() ORDER_PP_IS_ACTIVE(118)(,ORDER_PP_FIND_IN_111_118,ORDER_PP_FIND_IN_119_126)()
#define ORDER_PP_FIND_IN_119_120() ORDER_PP_IS_ACTIVE(119)(,120,119)
#define ORDER_PP_FIND_IN_119_122() ORDER_PP_IS_ACTIVE(120)(,ORDER_PP_FIND_IN_119_120,ORDER_PP_FIND_IN_121_122)()
#define ORDER_PP_FIND_IN_121_122() ORDER_PP_IS_ACTIVE(121)(,122,121)
#define ORDER_PP_FIND_IN_119_126() ORDER_PP_IS_ACTIVE(122)(,ORDER_PP_FIND_IN_119_122,ORDER_PP_FIND_IN_123_126)()
#define ORDER_PP_FIND_IN_123_124() ORDER_PP_IS_ACTIVE(123)(,124,123)
#define ORDER_PP_FIND_IN_123_126() ORDER_PP_IS_ACTIVE(124)(,ORDER_PP_FIND_IN_123_124,ORDER_PP_FIND_IN_125_126)()
#define ORDER_PP_FIND_IN_125_126() ORDER_PP_IS_ACTIVE(125)(,126,125)

#define ORDER_PP_FIND_GT_126() ORDER_PP_ERROR_OUT_OF_INTERPRETERS(!)

#define ORDER_PP_ERROR_OUT_OF_INTERPRETERS()

#define ORDER_PP_EVAL_0(t) ORDER_PP_SCAN_0(ORDER_PP_SCAN_0(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_1(t) ORDER_PP_SCAN_1(ORDER_PP_SCAN_1(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_2(t) ORDER_PP_SCAN_2(ORDER_PP_SCAN_2(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_3(t) ORDER_PP_SCAN_3(ORDER_PP_SCAN_3(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_4(t) ORDER_PP_SCAN_4(ORDER_PP_SCAN_4(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_5(t) ORDER_PP_SCAN_5(ORDER_PP_SCAN_5(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_6(t) ORDER_PP_SCAN_6(ORDER_PP_SCAN_6(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_7(t) ORDER_PP_SCAN_7(ORDER_PP_SCAN_7(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_8(t) ORDER_PP_SCAN_8(ORDER_PP_SCAN_8(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_9(t) ORDER_PP_SCAN_9(ORDER_PP_SCAN_9(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_10(t) ORDER_PP_SCAN_10(ORDER_PP_SCAN_10(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_11(t) ORDER_PP_SCAN_11(ORDER_PP_SCAN_11(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_12(t) ORDER_PP_SCAN_12(ORDER_PP_SCAN_12(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_13(t) ORDER_PP_SCAN_13(ORDER_PP_SCAN_13(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_14(t) ORDER_PP_SCAN_14(ORDER_PP_SCAN_14(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_15(t) ORDER_PP_SCAN_15(ORDER_PP_SCAN_15(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_16(t) ORDER_PP_SCAN_16(ORDER_PP_SCAN_16(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_17(t) ORDER_PP_SCAN_17(ORDER_PP_SCAN_17(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_18(t) ORDER_PP_SCAN_18(ORDER_PP_SCAN_18(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_19(t) ORDER_PP_SCAN_19(ORDER_PP_SCAN_19(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_20(t) ORDER_PP_SCAN_20(ORDER_PP_SCAN_20(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_21(t) ORDER_PP_SCAN_21(ORDER_PP_SCAN_21(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_22(t) ORDER_PP_SCAN_22(ORDER_PP_SCAN_22(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_23(t) ORDER_PP_SCAN_23(ORDER_PP_SCAN_23(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_24(t) ORDER_PP_SCAN_24(ORDER_PP_SCAN_24(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_25(t) ORDER_PP_SCAN_25(ORDER_PP_SCAN_25(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_26(t) ORDER_PP_SCAN_26(ORDER_PP_SCAN_26(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_27(t) ORDER_PP_SCAN_27(ORDER_PP_SCAN_27(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_28(t) ORDER_PP_SCAN_28(ORDER_PP_SCAN_28(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_29(t) ORDER_PP_SCAN_29(ORDER_PP_SCAN_29(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_30(t) ORDER_PP_SCAN_30(ORDER_PP_SCAN_30(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_31(t) ORDER_PP_SCAN_31(ORDER_PP_SCAN_31(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_32(t) ORDER_PP_SCAN_32(ORDER_PP_SCAN_32(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_33(t) ORDER_PP_SCAN_33(ORDER_PP_SCAN_33(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_34(t) ORDER_PP_SCAN_34(ORDER_PP_SCAN_34(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_35(t) ORDER_PP_SCAN_35(ORDER_PP_SCAN_35(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_36(t) ORDER_PP_SCAN_36(ORDER_PP_SCAN_36(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_37(t) ORDER_PP_SCAN_37(ORDER_PP_SCAN_37(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_38(t) ORDER_PP_SCAN_38(ORDER_PP_SCAN_38(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_39(t) ORDER_PP_SCAN_39(ORDER_PP_SCAN_39(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_40(t) ORDER_PP_SCAN_40(ORDER_PP_SCAN_40(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_41(t) ORDER_PP_SCAN_41(ORDER_PP_SCAN_41(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_42(t) ORDER_PP_SCAN_42(ORDER_PP_SCAN_42(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_43(t) ORDER_PP_SCAN_43(ORDER_PP_SCAN_43(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_44(t) ORDER_PP_SCAN_44(ORDER_PP_SCAN_44(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_45(t) ORDER_PP_SCAN_45(ORDER_PP_SCAN_45(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_46(t) ORDER_PP_SCAN_46(ORDER_PP_SCAN_46(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_47(t) ORDER_PP_SCAN_47(ORDER_PP_SCAN_47(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_48(t) ORDER_PP_SCAN_48(ORDER_PP_SCAN_48(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_49(t) ORDER_PP_SCAN_49(ORDER_PP_SCAN_49(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_50(t) ORDER_PP_SCAN_50(ORDER_PP_SCAN_50(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_51(t) ORDER_PP_SCAN_51(ORDER_PP_SCAN_51(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_52(t) ORDER_PP_SCAN_52(ORDER_PP_SCAN_52(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_53(t) ORDER_PP_SCAN_53(ORDER_PP_SCAN_53(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_54(t) ORDER_PP_SCAN_54(ORDER_PP_SCAN_54(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_55(t) ORDER_PP_SCAN_55(ORDER_PP_SCAN_55(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_56(t) ORDER_PP_SCAN_56(ORDER_PP_SCAN_56(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_57(t) ORDER_PP_SCAN_57(ORDER_PP_SCAN_57(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_58(t) ORDER_PP_SCAN_58(ORDER_PP_SCAN_58(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_59(t) ORDER_PP_SCAN_59(ORDER_PP_SCAN_59(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_60(t) ORDER_PP_SCAN_60(ORDER_PP_SCAN_60(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_61(t) ORDER_PP_SCAN_61(ORDER_PP_SCAN_61(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_62(t) ORDER_PP_SCAN_62(ORDER_PP_SCAN_62(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_63(t) ORDER_PP_SCAN_63(ORDER_PP_SCAN_63(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_64(t) ORDER_PP_SCAN_64(ORDER_PP_SCAN_64(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_65(t) ORDER_PP_SCAN_65(ORDER_PP_SCAN_65(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_66(t) ORDER_PP_SCAN_66(ORDER_PP_SCAN_66(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_67(t) ORDER_PP_SCAN_67(ORDER_PP_SCAN_67(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_68(t) ORDER_PP_SCAN_68(ORDER_PP_SCAN_68(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_69(t) ORDER_PP_SCAN_69(ORDER_PP_SCAN_69(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_70(t) ORDER_PP_SCAN_70(ORDER_PP_SCAN_70(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_71(t) ORDER_PP_SCAN_71(ORDER_PP_SCAN_71(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_72(t) ORDER_PP_SCAN_72(ORDER_PP_SCAN_72(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_73(t) ORDER_PP_SCAN_73(ORDER_PP_SCAN_73(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_74(t) ORDER_PP_SCAN_74(ORDER_PP_SCAN_74(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_75(t) ORDER_PP_SCAN_75(ORDER_PP_SCAN_75(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_76(t) ORDER_PP_SCAN_76(ORDER_PP_SCAN_76(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_77(t) ORDER_PP_SCAN_77(ORDER_PP_SCAN_77(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_78(t) ORDER_PP_SCAN_78(ORDER_PP_SCAN_78(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_79(t) ORDER_PP_SCAN_79(ORDER_PP_SCAN_79(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_80(t) ORDER_PP_SCAN_80(ORDER_PP_SCAN_80(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_81(t) ORDER_PP_SCAN_81(ORDER_PP_SCAN_81(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_82(t) ORDER_PP_SCAN_82(ORDER_PP_SCAN_82(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_83(t) ORDER_PP_SCAN_83(ORDER_PP_SCAN_83(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_84(t) ORDER_PP_SCAN_84(ORDER_PP_SCAN_84(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_85(t) ORDER_PP_SCAN_85(ORDER_PP_SCAN_85(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_86(t) ORDER_PP_SCAN_86(ORDER_PP_SCAN_86(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_87(t) ORDER_PP_SCAN_87(ORDER_PP_SCAN_87(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_88(t) ORDER_PP_SCAN_88(ORDER_PP_SCAN_88(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_89(t) ORDER_PP_SCAN_89(ORDER_PP_SCAN_89(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_90(t) ORDER_PP_SCAN_90(ORDER_PP_SCAN_90(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_91(t) ORDER_PP_SCAN_91(ORDER_PP_SCAN_91(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_92(t) ORDER_PP_SCAN_92(ORDER_PP_SCAN_92(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_93(t) ORDER_PP_SCAN_93(ORDER_PP_SCAN_93(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_94(t) ORDER_PP_SCAN_94(ORDER_PP_SCAN_94(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_95(t) ORDER_PP_SCAN_95(ORDER_PP_SCAN_95(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_96(t) ORDER_PP_SCAN_96(ORDER_PP_SCAN_96(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_97(t) ORDER_PP_SCAN_97(ORDER_PP_SCAN_97(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_98(t) ORDER_PP_SCAN_98(ORDER_PP_SCAN_98(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_99(t) ORDER_PP_SCAN_99(ORDER_PP_SCAN_99(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_100(t) ORDER_PP_SCAN_100(ORDER_PP_SCAN_100(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_101(t) ORDER_PP_SCAN_101(ORDER_PP_SCAN_101(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_102(t) ORDER_PP_SCAN_102(ORDER_PP_SCAN_102(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_103(t) ORDER_PP_SCAN_103(ORDER_PP_SCAN_103(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_104(t) ORDER_PP_SCAN_104(ORDER_PP_SCAN_104(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_105(t) ORDER_PP_SCAN_105(ORDER_PP_SCAN_105(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_106(t) ORDER_PP_SCAN_106(ORDER_PP_SCAN_106(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_107(t) ORDER_PP_SCAN_107(ORDER_PP_SCAN_107(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_108(t) ORDER_PP_SCAN_108(ORDER_PP_SCAN_108(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_109(t) ORDER_PP_SCAN_109(ORDER_PP_SCAN_109(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_110(t) ORDER_PP_SCAN_110(ORDER_PP_SCAN_110(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_111(t) ORDER_PP_SCAN_111(ORDER_PP_SCAN_111(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_112(t) ORDER_PP_SCAN_112(ORDER_PP_SCAN_112(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_113(t) ORDER_PP_SCAN_113(ORDER_PP_SCAN_113(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_114(t) ORDER_PP_SCAN_114(ORDER_PP_SCAN_114(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_115(t) ORDER_PP_SCAN_115(ORDER_PP_SCAN_115(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_116(t) ORDER_PP_SCAN_116(ORDER_PP_SCAN_116(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_117(t) ORDER_PP_SCAN_117(ORDER_PP_SCAN_117(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_118(t) ORDER_PP_SCAN_118(ORDER_PP_SCAN_118(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_119(t) ORDER_PP_SCAN_119(ORDER_PP_SCAN_119(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_120(t) ORDER_PP_SCAN_120(ORDER_PP_SCAN_120(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_121(t) ORDER_PP_SCAN_121(ORDER_PP_SCAN_121(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_122(t) ORDER_PP_SCAN_122(ORDER_PP_SCAN_122(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_123(t) ORDER_PP_SCAN_123(ORDER_PP_SCAN_123(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_124(t) ORDER_PP_SCAN_124(ORDER_PP_SCAN_124(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_125(t) ORDER_PP_SCAN_125(ORDER_PP_SCAN_125(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))
#define ORDER_PP_EVAL_126(t) ORDER_PP_SCAN_126(ORDER_PP_SCAN_126(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,))))

#define ORDER_PP_SCAN_0(...) __VA_ARGS__
#define ORDER_PP_SCAN_1(...) __VA_ARGS__
#define ORDER_PP_SCAN_2(...) __VA_ARGS__
#define ORDER_PP_SCAN_3(...) __VA_ARGS__
#define ORDER_PP_SCAN_4(...) __VA_ARGS__
#define ORDER_PP_SCAN_5(...) __VA_ARGS__
#define ORDER_PP_SCAN_6(...) __VA_ARGS__
#define ORDER_PP_SCAN_7(...) __VA_ARGS__
#define ORDER_PP_SCAN_8(...) __VA_ARGS__
#define ORDER_PP_SCAN_9(...) __VA_ARGS__
#define ORDER_PP_SCAN_10(...) __VA_ARGS__
#define ORDER_PP_SCAN_11(...) __VA_ARGS__
#define ORDER_PP_SCAN_12(...) __VA_ARGS__
#define ORDER_PP_SCAN_13(...) __VA_ARGS__
#define ORDER_PP_SCAN_14(...) __VA_ARGS__
#define ORDER_PP_SCAN_15(...) __VA_ARGS__
#define ORDER_PP_SCAN_16(...) __VA_ARGS__
#define ORDER_PP_SCAN_17(...) __VA_ARGS__
#define ORDER_PP_SCAN_18(...) __VA_ARGS__
#define ORDER_PP_SCAN_19(...) __VA_ARGS__
#define ORDER_PP_SCAN_20(...) __VA_ARGS__
#define ORDER_PP_SCAN_21(...) __VA_ARGS__
#define ORDER_PP_SCAN_22(...) __VA_ARGS__
#define ORDER_PP_SCAN_23(...) __VA_ARGS__
#define ORDER_PP_SCAN_24(...) __VA_ARGS__
#define ORDER_PP_SCAN_25(...) __VA_ARGS__
#define ORDER_PP_SCAN_26(...) __VA_ARGS__
#define ORDER_PP_SCAN_27(...) __VA_ARGS__
#define ORDER_PP_SCAN_28(...) __VA_ARGS__
#define ORDER_PP_SCAN_29(...) __VA_ARGS__
#define ORDER_PP_SCAN_30(...) __VA_ARGS__
#define ORDER_PP_SCAN_31(...) __VA_ARGS__
#define ORDER_PP_SCAN_32(...) __VA_ARGS__
#define ORDER_PP_SCAN_33(...) __VA_ARGS__
#define ORDER_PP_SCAN_34(...) __VA_ARGS__
#define ORDER_PP_SCAN_35(...) __VA_ARGS__
#define ORDER_PP_SCAN_36(...) __VA_ARGS__
#define ORDER_PP_SCAN_37(...) __VA_ARGS__
#define ORDER_PP_SCAN_38(...) __VA_ARGS__
#define ORDER_PP_SCAN_39(...) __VA_ARGS__
#define ORDER_PP_SCAN_40(...) __VA_ARGS__
#define ORDER_PP_SCAN_41(...) __VA_ARGS__
#define ORDER_PP_SCAN_42(...) __VA_ARGS__
#define ORDER_PP_SCAN_43(...) __VA_ARGS__
#define ORDER_PP_SCAN_44(...) __VA_ARGS__
#define ORDER_PP_SCAN_45(...) __VA_ARGS__
#define ORDER_PP_SCAN_46(...) __VA_ARGS__
#define ORDER_PP_SCAN_47(...) __VA_ARGS__
#define ORDER_PP_SCAN_48(...) __VA_ARGS__
#define ORDER_PP_SCAN_49(...) __VA_ARGS__
#define ORDER_PP_SCAN_50(...) __VA_ARGS__
#define ORDER_PP_SCAN_51(...) __VA_ARGS__
#define ORDER_PP_SCAN_52(...) __VA_ARGS__
#define ORDER_PP_SCAN_53(...) __VA_ARGS__
#define ORDER_PP_SCAN_54(...) __VA_ARGS__
#define ORDER_PP_SCAN_55(...) __VA_ARGS__
#define ORDER_PP_SCAN_56(...) __VA_ARGS__
#define ORDER_PP_SCAN_57(...) __VA_ARGS__
#define ORDER_PP_SCAN_58(...) __VA_ARGS__
#define ORDER_PP_SCAN_59(...) __VA_ARGS__
#define ORDER_PP_SCAN_60(...) __VA_ARGS__
#define ORDER_PP_SCAN_61(...) __VA_ARGS__
#define ORDER_PP_SCAN_62(...) __VA_ARGS__
#define ORDER_PP_SCAN_63(...) __VA_ARGS__
#define ORDER_PP_SCAN_64(...) __VA_ARGS__
#define ORDER_PP_SCAN_65(...) __VA_ARGS__
#define ORDER_PP_SCAN_66(...) __VA_ARGS__
#define ORDER_PP_SCAN_67(...) __VA_ARGS__
#define ORDER_PP_SCAN_68(...) __VA_ARGS__
#define ORDER_PP_SCAN_69(...) __VA_ARGS__
#define ORDER_PP_SCAN_70(...) __VA_ARGS__
#define ORDER_PP_SCAN_71(...) __VA_ARGS__
#define ORDER_PP_SCAN_72(...) __VA_ARGS__
#define ORDER_PP_SCAN_73(...) __VA_ARGS__
#define ORDER_PP_SCAN_74(...) __VA_ARGS__
#define ORDER_PP_SCAN_75(...) __VA_ARGS__
#define ORDER_PP_SCAN_76(...) __VA_ARGS__
#define ORDER_PP_SCAN_77(...) __VA_ARGS__
#define ORDER_PP_SCAN_78(...) __VA_ARGS__
#define ORDER_PP_SCAN_79(...) __VA_ARGS__
#define ORDER_PP_SCAN_80(...) __VA_ARGS__
#define ORDER_PP_SCAN_81(...) __VA_ARGS__
#define ORDER_PP_SCAN_82(...) __VA_ARGS__
#define ORDER_PP_SCAN_83(...) __VA_ARGS__
#define ORDER_PP_SCAN_84(...) __VA_ARGS__
#define ORDER_PP_SCAN_85(...) __VA_ARGS__
#define ORDER_PP_SCAN_86(...) __VA_ARGS__
#define ORDER_PP_SCAN_87(...) __VA_ARGS__
#define ORDER_PP_SCAN_88(...) __VA_ARGS__
#define ORDER_PP_SCAN_89(...) __VA_ARGS__
#define ORDER_PP_SCAN_90(...) __VA_ARGS__
#define ORDER_PP_SCAN_91(...) __VA_ARGS__
#define ORDER_PP_SCAN_92(...) __VA_ARGS__
#define ORDER_PP_SCAN_93(...) __VA_ARGS__
#define ORDER_PP_SCAN_94(...) __VA_ARGS__
#define ORDER_PP_SCAN_95(...) __VA_ARGS__
#define ORDER_PP_SCAN_96(...) __VA_ARGS__
#define ORDER_PP_SCAN_97(...) __VA_ARGS__
#define ORDER_PP_SCAN_98(...) __VA_ARGS__
#define ORDER_PP_SCAN_99(...) __VA_ARGS__
#define ORDER_PP_SCAN_100(...) __VA_ARGS__
#define ORDER_PP_SCAN_101(...) __VA_ARGS__
#define ORDER_PP_SCAN_102(...) __VA_ARGS__
#define ORDER_PP_SCAN_103(...) __VA_ARGS__
#define ORDER_PP_SCAN_104(...) __VA_ARGS__
#define ORDER_PP_SCAN_105(...) __VA_ARGS__
#define ORDER_PP_SCAN_106(...) __VA_ARGS__
#define ORDER_PP_SCAN_107(...) __VA_ARGS__
#define ORDER_PP_SCAN_108(...) __VA_ARGS__
#define ORDER_PP_SCAN_109(...) __VA_ARGS__
#define ORDER_PP_SCAN_110(...) __VA_ARGS__
#define ORDER_PP_SCAN_111(...) __VA_ARGS__
#define ORDER_PP_SCAN_112(...) __VA_ARGS__
#define ORDER_PP_SCAN_113(...) __VA_ARGS__
#define ORDER_PP_SCAN_114(...) __VA_ARGS__
#define ORDER_PP_SCAN_115(...) __VA_ARGS__
#define ORDER_PP_SCAN_116(...) __VA_ARGS__
#define ORDER_PP_SCAN_117(...) __VA_ARGS__
#define ORDER_PP_SCAN_118(...) __VA_ARGS__
#define ORDER_PP_SCAN_119(...) __VA_ARGS__
#define ORDER_PP_SCAN_120(...) __VA_ARGS__
#define ORDER_PP_SCAN_121(...) __VA_ARGS__
#define ORDER_PP_SCAN_122(...) __VA_ARGS__
#define ORDER_PP_SCAN_123(...) __VA_ARGS__
#define ORDER_PP_SCAN_124(...) __VA_ARGS__
#define ORDER_PP_SCAN_125(...) __VA_ARGS__
#define ORDER_PP_SCAN_126(...) __VA_ARGS__

#endif
