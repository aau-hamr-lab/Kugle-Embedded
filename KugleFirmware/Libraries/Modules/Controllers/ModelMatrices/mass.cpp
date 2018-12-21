//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: mass.cpp
//
// MATLAB Coder version            : 4.0
// C/C++ source code generated on  : 20-Nov-2018 22:55:49
//

// Include Files
#include "rt_nonfinite.h"
#include "mass.h"

// Function Definitions

//
// function M = mass(COM_X,COM_Y,COM_Z,Jbx,Jby,Jbz,Jk,Jw,Mb,Mk,q1,q2,q3,q4,rk,rw)
// MASS
//     M = MASS(COM_X,COM_Y,COM_Z,JBX,JBY,JBZ,JK,JW,MB,MK,Q1,Q2,Q3,Q4,RK,RW)
// Arguments    : float COM_X
//                float COM_Y
//                float COM_Z
//                float Jbx
//                float Jby
//                float Jbz
//                float Jk
//                float Jw
//                float Mb
//                float Mk
//                float q1
//                float q2
//                float q3
//                float q4
//                float rk
//                float rw
//                float M[36]
// Return Type  : void
//
void mass(float COM_X, float COM_Y, float COM_Z, float Jbx, float Jby, float Jbz,
          float Jk, float Jw, float Mb, float Mk, float q1, float q2, float q3,
          float q4, float rk, float rw, float M[36])
{
  float t2;
  float t3;
  float t4;
  float t5;
  float t6;
  float t7;
  float t8;
  float t12;
  float t13;
  float t14;
  float t16;
  float t18;
  float t20;
  float t22;
  float t23;
  float t24;
  float t25;
  float t26;
  float t27;
  float t28;
  float t29;
  float t30;
  float t31;
  float t32;
  float t33;
  float t34;
  float t35;
  float t36;
  float t37;
  float t38;
  float t39;
  float t40;
  float t41;
  float t42;
  float t43;
  float t44;
  float t45;
  float t46;
  float t47;
  float t48;
  float t49;
  float t50;
  float t128;
  float t129;
  float t53;
  float t130;
  float t131;
  float t56;
  float t132;
  float t59;
  float t133;
  float t134;
  float t135;
  float t62;
  float t63;
  float t64;
  float t65;
  float t66;
  float t67;
  float t68;
  float t69;
  float t74;
  float t75;
  float t76;
  float t87;
  float t88;
  float t89;
  float t77;
  float t78;
  float t79;
  float t80;
  float t81;
  float t82;
  float t83;
  float t84;
  float t85;
  float t86;
  float t90;
  float t91;
  float t92;
  float t93;
  float t94;
  float t95;
  float t96;
  float t97;
  float t98;
  float t99;
  float t100;
  float t101;
  float t102;
  float t103;
  float t108;
  float t110;
  float t136;
  float t115;
  float t120;
  float t121;
  float t122;
  float t124;
  float t125;
  float t126;
  float t127;
  float t141;
  float t142;
  float t143;
  float t144;
  float t147;
  float t148;
  float t153;
  float t154;
  float t155;
  float t156;
  float t157;
  float t166;
  float t171;
  float t176;
  float x[36];
  int i0;
  int i1;
  int i2;
  int i3;

  //     This function was generated by the Symbolic Math Toolbox version 8.1.
  //     12-Nov-2018 22:44:27
  // 'mass:8' t2 = q1.^2;
  t2 = q1 * q1;

  // 'mass:9' t3 = q2.^2;
  t3 = q2 * q2;

  // 'mass:10' t4 = rk.^2;
  t4 = rk * rk;

  // 'mass:11' t5 = q3.^2;
  t5 = q3 * q3;

  // 'mass:12' t6 = q4.^2;
  t6 = q4 * q4;

  // 'mass:13' t7 = rw.^2;
  t7 = rw * rw;

  // 'mass:14' t8 = 1.0./rw.^2;
  t8 = 1.0F / (rw * rw);

  // 'mass:15' t9 = q2.*q3.*t2;
  // 'mass:16' t10 = q1.*q4.*t3;
  // 'mass:17' t11 = t9+t10-q1.*q4.*t5-q2.*q3.*t6;
  // 'mass:18' t12 = Jw.*t8.*t11.*3.0;
  t12 = Jw * t8 * (((q2 * q3 * t2 + q1 * q4 * t3) - q1 * q4 * t5) - q2 * q3 * t6)
    * 3.0F;

  // 'mass:19' t13 = 1.0./rk.^2;
  t13 = 1.0F / (rk * rk);

  // 'mass:20' t14 = Jk.*t7.*4.0;
  t14 = Jk * t7 * 4.0F;

  // 'mass:21' t15 = t2.^2;
  // 'mass:22' t16 = Jw.*t4.*t15.*3.0;
  t16 = Jw * t4 * (t2 * t2) * 3.0F;

  // 'mass:23' t17 = t3.^2;
  // 'mass:24' t18 = Jw.*t4.*t17.*3.0;
  t18 = Jw * t4 * (t3 * t3) * 3.0F;

  // 'mass:25' t19 = t5.^2;
  // 'mass:26' t20 = Jw.*t4.*t19.*3.0;
  t20 = Jw * t4 * (t5 * t5) * 3.0F;

  // 'mass:27' t21 = t6.^2;
  // 'mass:28' t22 = Jw.*t4.*t21.*3.0;
  t22 = Jw * t4 * (t6 * t6) * 3.0F;

  // 'mass:29' t23 = Mb.*t4.*t7.*4.0;
  t23 = Mb * t4 * t7 * 4.0F;

  // 'mass:30' t24 = Mk.*t4.*t7.*4.0;
  t24 = Mk * t4 * t7 * 4.0F;

  // 'mass:31' t25 = Jw.*t2.*t4.*t6.*6.0;
  t25 = Jw * t2 * t4 * t6 * 6.0F;

  // 'mass:32' t26 = Jw.*t3.*t4.*t5.*6.0;
  t26 = Jw * t3 * t4 * t5 * 6.0F;

  // 'mass:33' t27 = Jw.*q2.*rk.*t3.*3.0;
  t27 = Jw * q2 * rk * t3 * 3.0F;

  // 'mass:34' t28 = COM_Z.*Mb.*q2.*t7.*4.0;
  t28 = COM_Z * Mb * q2 * t7 * 4.0F;

  // 'mass:35' t29 = Jw.*q2.*rk.*t5.*3.0;
  t29 = Jw * q2 * rk * t5 * 3.0F;

  // 'mass:36' t30 = Jw.*q1.*rk.*t2.*3.0;
  t30 = Jw * q1 * rk * t2 * 3.0F;

  // 'mass:37' t31 = COM_X.*Mb.*q3.*t7.*4.0;
  t31 = COM_X * Mb * q3 * t7 * 4.0F;

  // 'mass:38' t32 = Jw.*q1.*rk.*t6.*3.0;
  t32 = Jw * q1 * rk * t6 * 3.0F;

  // 'mass:39' t33 = Jw.*q4.*rk.*t6.*3.0;
  t33 = Jw * q4 * rk * t6 * 3.0F;

  // 'mass:40' t34 = Jw.*q4.*rk.*t2.*3.0;
  t34 = Jw * q4 * rk * t2 * 3.0F;

  // 'mass:41' t35 = Jw.*q3.*rk.*t5.*3.0;
  t35 = Jw * q3 * rk * t5 * 3.0F;

  // 'mass:42' t36 = COM_X.*Mb.*q1.*t7.*4.0;
  t36 = COM_X * Mb * q1 * t7 * 4.0F;

  // 'mass:43' t37 = COM_Z.*Mb.*q3.*t7.*4.0;
  t37 = COM_Z * Mb * q3 * t7 * 4.0F;

  // 'mass:44' t38 = Jw.*q3.*rk.*t3.*3.0;
  t38 = Jw * q3 * rk * t3 * 3.0F;

  // 'mass:45' t39 = Jw.*q1.*rk.*t3.*9.0;
  t39 = Jw * q1 * rk * t3 * 9.0F;

  // 'mass:46' t40 = Jw.*q1.*rk.*t5.*3.0;
  t40 = Jw * q1 * rk * t5 * 3.0F;

  // 'mass:47' t41 = Jw.*q2.*q3.*q4.*rk.*6.0;
  t41 = Jw * q2 * q3 * q4 * rk * 6.0F;

  // 'mass:48' t42 = Jw.*q2.*rk.*t2.*9.0;
  t42 = Jw * q2 * rk * t2 * 9.0F;

  // 'mass:49' t43 = Jw.*q2.*rk.*t6.*3.0;
  t43 = Jw * q2 * rk * t6 * 3.0F;

  // 'mass:50' t44 = Jw.*q1.*q3.*q4.*rk.*6.0;
  t44 = Jw * q1 * q3 * q4 * rk * 6.0F;

  // 'mass:51' t45 = Jw.*q3.*rk.*t2.*3.0;
  t45 = Jw * q3 * rk * t2 * 3.0F;

  // 'mass:52' t46 = Jw.*q3.*rk.*t6.*9.0;
  t46 = Jw * q3 * rk * t6 * 9.0F;

  // 'mass:53' t47 = Jw.*q1.*q2.*q4.*rk.*6.0;
  t47 = Jw * q1 * q2 * q4 * rk * 6.0F;

  // 'mass:54' t48 = Jw.*q4.*rk.*t3.*3.0;
  t48 = Jw * q4 * rk * t3 * 3.0F;

  // 'mass:55' t49 = Jw.*q4.*rk.*t5.*9.0;
  t49 = Jw * q4 * rk * t5 * 9.0F;

  // 'mass:56' t50 = Jw.*q1.*q2.*q3.*rk.*6.0;
  t50 = Jw * q1 * q2 * q3 * rk * 6.0F;

  // 'mass:57' t51 = Jw.*q1.*rk.*t3.*3.0;
  // 'mass:58' t52 = Jw.*q1.*rk.*t5.*9.0;
  // 'mass:59' t128 = COM_Y.*Mb.*q2.*t7.*4.0;
  t128 = COM_Y * Mb * q2 * t7 * 4.0F;

  // 'mass:60' t129 = COM_Z.*Mb.*q1.*t7.*4.0;
  t129 = COM_Z * Mb * q1 * t7 * 4.0F;

  // 'mass:61' t53 = t30+t31+t32+t41+t51+t52-t128-t129;
  t53 = ((((((t30 + t31) + t32) + t41) + Jw * q1 * rk * t3 * 3.0F) + Jw * q1 *
          rk * t5 * 9.0F) - t128) - t129;

  // 'mass:62' t54 = Jw.*q2.*rk.*t2.*3.0;
  // 'mass:63' t55 = Jw.*q2.*rk.*t6.*9.0;
  // 'mass:64' t130 = COM_Y.*Mb.*q1.*t7.*4.0;
  t130 = COM_Y * Mb * q1 * t7 * 4.0F;

  // 'mass:65' t131 = COM_X.*Mb.*q4.*t7.*4.0;
  t131 = COM_X * Mb * q4 * t7 * 4.0F;

  // 'mass:66' t56 = t27+t28+t29+t44+t54+t55-t130-t131;
  t56 = ((((((t27 + t28) + t29) + t44) + Jw * q2 * rk * t2 * 3.0F) + Jw * q2 *
          rk * t6 * 9.0F) - t130) - t131;

  // 'mass:67' t57 = Jw.*q3.*rk.*t2.*9.0;
  // 'mass:68' t58 = Jw.*q3.*rk.*t6.*3.0;
  // 'mass:69' t132 = COM_Y.*Mb.*q4.*t7.*4.0;
  t132 = COM_Y * Mb * q4 * t7 * 4.0F;

  // 'mass:70' t59 = t35+t36+t37+t38+t47+t57+t58-t132;
  t59 = ((((((t35 + t36) + t37) + t38) + t47) + Jw * q3 * rk * t2 * 9.0F) + Jw *
         q3 * rk * t6 * 3.0F) - t132;

  // 'mass:71' t60 = Jw.*q4.*rk.*t3.*9.0;
  // 'mass:72' t61 = Jw.*q4.*rk.*t5.*3.0;
  // 'mass:73' t133 = COM_X.*Mb.*q2.*t7.*4.0;
  t133 = COM_X * Mb * q2 * t7 * 4.0F;

  // 'mass:74' t134 = COM_Y.*Mb.*q3.*t7.*4.0;
  t134 = COM_Y * Mb * q3 * t7 * 4.0F;

  // 'mass:75' t135 = COM_Z.*Mb.*q4.*t7.*4.0;
  t135 = COM_Z * Mb * q4 * t7 * 4.0F;

  // 'mass:76' t62 = t33+t34+t50+t60+t61-t133-t134-t135;
  t62 = ((((((t33 + t34) + t50) + Jw * q4 * rk * t3 * 9.0F) + Jw * q4 * rk * t5 *
           3.0F) - t133) - t134) - t135;

  // 'mass:77' t63 = COM_Y.^2;
  t63 = COM_Y * COM_Y;

  // 'mass:78' t64 = COM_X.^2;
  t64 = COM_X * COM_X;

  // 'mass:79' t65 = COM_Z.^2;
  t65 = COM_Z * COM_Z;

  // 'mass:80' t66 = COM_X.*COM_Y.*Mb.*q1.*q2.*4.0;
  t66 = COM_X * COM_Y * Mb * q1 * q2 * 4.0F;

  // 'mass:81' t67 = COM_X.*COM_Y.*Mb.*q3.*q4.*4.0;
  t67 = COM_X * COM_Y * Mb * q3 * q4 * 4.0F;

  // 'mass:82' t68 = COM_Y.*COM_Z.*Mb.*q1.*q4.*4.0;
  t68 = COM_Y * COM_Z * Mb * q1 * q4 * 4.0F;

  // 'mass:83' t69 = Jw.*q2.*q4.*t4.*t8.*3.0;
  t69 = Jw * q2 * q4 * t4 * t8 * 3.0F;

  // 'mass:84' t70 = Jbx.*q1.*q2.*4.0;
  // 'mass:85' t71 = Jbz.*q3.*q4.*4.0;
  // 'mass:86' t72 = COM_Y.*COM_Z.*Mb.*t6.*4.0;
  // 'mass:87' t73 = Mb.*q3.*q4.*t63.*4.0;
  // 'mass:88' t74 = COM_X.*COM_Y.*Mb.*q2.*q4.*4.0;
  t74 = COM_X * COM_Y * Mb * q2 * q4 * 4.0F;

  // 'mass:89' t75 = Jw.*q1.*q2.*t4.*t8.*3.0;
  t75 = Jw * q1 * q2 * t4 * t8 * 3.0F;

  // 'mass:90' t76 = Jw.*q3.*q4.*t4.*t8.*3.0;
  t76 = Jw * q3 * q4 * t4 * t8 * 3.0F;

  // 'mass:91' t87 = COM_X.*COM_Y.*Mb.*q1.*q3.*4.0;
  t87 = COM_X * COM_Y * Mb * q1 * q3 * 4.0F;

  // 'mass:92' t88 = COM_X.*COM_Z.*Mb.*q1.*q4.*4.0;
  t88 = COM_X * COM_Z * Mb * q1 * q4 * 4.0F;

  // 'mass:93' t89 = COM_X.*COM_Z.*Mb.*q2.*q3.*4.0;
  t89 = COM_X * COM_Z * Mb * q2 * q3 * 4.0F;

  // 'mass:94' t137 = Jby.*q3.*q4.*4.0;
  // 'mass:95' t138 = COM_Y.*COM_Z.*Mb.*t5.*4.0;
  // 'mass:96' t139 = Mb.*q1.*q2.*t64.*4.0;
  // 'mass:97' t140 = Mb.*q3.*q4.*t65.*4.0;
  // 'mass:98' t77 = t70+t71+t72+t73+t74+t75+t76-t87-t88-t89-t137-t138-t139-t140; 
  t77 = ((((((((((((Jbx * q1 * q2 * 4.0F + Jbz * q3 * q4 * 4.0F) + COM_Y * COM_Z
                   * Mb * t6 * 4.0F) + Mb * q3 * q4 * t63 * 4.0F) + t74) + t75)
               + t76) - t87) - t88) - t89) - Jby * q3 * q4 * 4.0F) - COM_Y *
          COM_Z * Mb * t5 * 4.0F) - Mb * q1 * q2 * t64 * 4.0F) - Mb * q3 * q4 *
    t65 * 4.0F;

  // 'mass:99' t78 = Mb.*t2.*t63.*4.0;
  t78 = Mb * t2 * t63 * 4.0F;

  // 'mass:100' t79 = Mb.*t5.*t64.*4.0;
  t79 = Mb * t5 * t64 * 4.0F;

  // 'mass:101' t80 = Mb.*t3.*t63.*4.0;
  t80 = Mb * t3 * t63 * 4.0F;

  // 'mass:102' t81 = Mb.*t2.*t65.*4.0;
  t81 = Mb * t2 * t65 * 4.0F;

  // 'mass:103' t82 = Mb.*t6.*t64.*4.0;
  t82 = Mb * t6 * t64 * 4.0F;

  // 'mass:104' t83 = Mb.*t3.*t65.*4.0;
  t83 = Mb * t3 * t65 * 4.0F;

  // 'mass:105' t84 = COM_X.*COM_Z.*Mb.*q1.*q2.*4.0;
  t84 = COM_X * COM_Z * Mb * q1 * q2 * 4.0F;

  // 'mass:106' t85 = COM_Y.*COM_Z.*Mb.*q1.*q3.*4.0;
  t85 = COM_Y * COM_Z * Mb * q1 * q3 * 4.0F;

  // 'mass:107' t86 = COM_Y.*COM_Z.*Mb.*q2.*q4.*4.0;
  t86 = COM_Y * COM_Z * Mb * q2 * q4 * 4.0F;

  // 'mass:108' t90 = Jbz.*q2.*q4.*4.0;
  t90 = Jbz * q2 * q4 * 4.0F;

  // 'mass:109' t91 = COM_X.*COM_Z.*Mb.*t6.*4.0;
  t91 = COM_X * COM_Z * Mb * t6 * 4.0F;

  // 'mass:110' t92 = Mb.*q1.*q3.*t63.*4.0;
  t92 = Mb * q1 * q3 * t63 * 4.0F;

  // 'mass:111' t93 = Mb.*q2.*q4.*t64.*4.0;
  t93 = Mb * q2 * q4 * t64 * 4.0F;

  // 'mass:112' t94 = COM_Y.*COM_Z.*Mb.*q2.*q3.*4.0;
  t94 = COM_Y * COM_Z * Mb * q2 * q3 * 4.0F;

  // 'mass:113' t95 = Mb.*t2.*t64.*4.0;
  t95 = Mb * t2 * t64 * 4.0F;

  // 'mass:114' t96 = Mb.*t3.*t64.*4.0;
  t96 = Mb * t3 * t64 * 4.0F;

  // 'mass:115' t97 = Mb.*t5.*t63.*4.0;
  t97 = Mb * t5 * t63 * 4.0F;

  // 'mass:116' t98 = Mb.*t6.*t63.*4.0;
  t98 = Mb * t6 * t63 * 4.0F;

  // 'mass:117' t99 = Mb.*t5.*t65.*4.0;
  t99 = Mb * t5 * t65 * 4.0F;

  // 'mass:118' t100 = Mb.*t6.*t65.*4.0;
  t100 = Mb * t6 * t65 * 4.0F;

  // 'mass:119' t101 = Jw.*t2.*t4.*t8.*3.0;
  t101 = Jw * t2 * t4 * t8 * 3.0F;

  // 'mass:120' t102 = Jw.*t4.*t6.*t8.*3.0;
  t102 = Jw * t4 * t6 * t8 * 3.0F;

  // 'mass:121' t103 = COM_X.*COM_Y.*Mb.*q1.*q4.*8.0;
  t103 = COM_X * COM_Y * Mb * q1 * q4 * 8.0F;

  // 'mass:122' t104 = Jby.*q1.*q4.*4.0;
  // 'mass:123' t105 = Jbz.*q2.*q3.*4.0;
  // 'mass:124' t106 = COM_X.*COM_Y.*Mb.*t2.*4.0;
  // 'mass:125' t107 = Mb.*q1.*q4.*t64.*4.0;
  // 'mass:126' t108 = COM_X.*COM_Z.*Mb.*q3.*q4.*4.0;
  t108 = COM_X * COM_Z * Mb * q3 * q4 * 4.0F;

  // 'mass:127' t109 = Jw.*q2.*q3.*t4.*t8.*6.0;
  // 'mass:128' t158 = Jbx.*q1.*q4.*4.0;
  // 'mass:129' t159 = COM_X.*COM_Y.*Mb.*t6.*4.0;
  // 'mass:130' t160 = Mb.*q1.*q4.*t63.*4.0;
  // 'mass:131' t161 = Mb.*q2.*q3.*t65.*4.0;
  // 'mass:132' t110 = -t84+t85+t86+t104+t105+t106+t107+t108+t109-t158-t159-t160-t161; 
  t110 = (((((((((((-t84 + t85) + t86) + Jby * q1 * q4 * 4.0F) + Jbz * q2 * q3 *
                 4.0F) + COM_X * COM_Y * Mb * t2 * 4.0F) + Mb * q1 * q4 * t64 *
               4.0F) + t108) + Jw * q2 * q3 * t4 * t8 * 6.0F) - Jbx * q1 * q4 *
            4.0F) - COM_X * COM_Y * Mb * t6 * 4.0F) - Mb * q1 * q4 * t63 * 4.0F)
    - Mb * q2 * q3 * t65 * 4.0F;

  // 'mass:133' t111 = Jbx.*q1.*q3.*4.0;
  // 'mass:134' t112 = Jby.*q2.*q4.*4.0;
  // 'mass:135' t113 = COM_X.*COM_Z.*Mb.*t2.*4.0;
  // 'mass:136' t114 = Mb.*q1.*q3.*t65.*4.0;
  // 'mass:137' t136 = Jw.*q1.*q3.*t4.*t8.*3.0;
  t136 = Jw * q1 * q3 * t4 * t8 * 3.0F;

  // 'mass:138' t149 = Jbz.*q1.*q3.*4.0;
  // 'mass:139' t150 = COM_X.*COM_Z.*Mb.*t5.*4.0;
  // 'mass:140' t151 = Mb.*q1.*q3.*t64.*4.0;
  // 'mass:141' t152 = Mb.*q2.*q4.*t63.*4.0;
  // 'mass:142' t115 = t66+t67-t68+t69+t94+t111+t112+t113+t114-t136-t149-t150-t151-t152; 
  t115 = ((((((((((((t66 + t67) - t68) + t69) + t94) + Jbx * q1 * q3 * 4.0F) +
                Jby * q2 * q4 * 4.0F) + COM_X * COM_Z * Mb * t2 * 4.0F) + Mb *
              q1 * q3 * t65 * 4.0F) - t136) - Jbz * q1 * q3 * 4.0F) - COM_X *
           COM_Z * Mb * t5 * 4.0F) - Mb * q1 * q3 * t64 * 4.0F) - Mb * q2 * q4 *
    t63 * 4.0F;

  // 'mass:143' t116 = Jbx.*q3.*q4.*4.0;
  // 'mass:144' t117 = Jbz.*q1.*q2.*4.0;
  // 'mass:145' t118 = COM_Y.*COM_Z.*Mb.*t2.*4.0;
  // 'mass:146' t119 = Mb.*q1.*q2.*t63.*4.0;
  // 'mass:147' t162 = Jby.*q1.*q2.*4.0;
  // 'mass:148' t163 = COM_Y.*COM_Z.*Mb.*t3.*4.0;
  // 'mass:149' t164 = Mb.*q1.*q2.*t65.*4.0;
  // 'mass:150' t165 = Mb.*q3.*q4.*t64.*4.0;
  // 'mass:151' t120 = t74+t75+t76-t87+t88+t89+t116+t117+t118+t119-t162-t163-t164-t165; 
  t120 = ((((((((((((t74 + t75) + t76) - t87) + t88) + t89) + Jbx * q3 * q4 *
                4.0F) + Jbz * q1 * q2 * 4.0F) + COM_Y * COM_Z * Mb * t2 * 4.0F)
             + Mb * q1 * q2 * t63 * 4.0F) - Jby * q1 * q2 * 4.0F) - COM_Y *
           COM_Z * Mb * t3 * 4.0F) - Mb * q1 * q2 * t65 * 4.0F) - Mb * q3 * q4 *
    t64 * 4.0F;

  // 'mass:152' t121 = Jw.*t3.*t4.*t8.*3.0;
  t121 = Jw * t3 * t4 * t8 * 3.0F;

  // 'mass:153' t122 = Jw.*t4.*t5.*t8.*3.0;
  t122 = Jw * t4 * t5 * t8 * 3.0F;

  // 'mass:154' t123 = COM_Y.*COM_Z.*Mb.*q1.*q2.*8.0;
  t74 = COM_Y * COM_Z * Mb * q1 * q2 * 8.0F;

  // 'mass:155' t124 = Jbx.*q2.*q3.*4.0;
  t124 = Jbx * q2 * q3 * 4.0F;

  // 'mass:156' t125 = COM_X.*COM_Y.*Mb.*t3.*4.0;
  t125 = COM_X * COM_Y * Mb * t3 * 4.0F;

  // 'mass:157' t126 = Mb.*q2.*q3.*t63.*4.0;
  t126 = Mb * q2 * q3 * t63 * 4.0F;

  // 'mass:158' t127 = Mb.*q1.*q4.*t65.*4.0;
  t127 = Mb * q1 * q4 * t65 * 4.0F;

  // 'mass:159' t141 = Jbx.*t3.*4.0;
  t141 = Jbx * t3 * 4.0F;

  // 'mass:160' t142 = Jby.*t5.*4.0;
  t142 = Jby * t5 * 4.0F;

  // 'mass:161' t143 = Jbz.*t6.*4.0;
  t143 = Jbz * t6 * 4.0F;

  // 'mass:162' t144 = Jw.*t4.*t6.*t8.*6.0;
  t144 = Jw * t4 * t6 * t8 * 6.0F;

  // 'mass:163' t145 = COM_X.*COM_Y.*Mb.*q2.*q3.*8.0;
  t75 = COM_X * COM_Y * Mb * q2 * q3 * 8.0F;

  // 'mass:164' t146 = COM_X.*COM_Z.*Mb.*q2.*q4.*8.0;
  t76 = COM_X * COM_Z * Mb * q2 * q4 * 8.0F;

  // 'mass:165' t147 = COM_Y.*COM_Z.*Mb.*q3.*q4.*8.0;
  t147 = COM_Y * COM_Z * Mb * q3 * q4 * 8.0F;

  // 'mass:166' t177 = Jby.*q2.*q3.*4.0;
  // 'mass:167' t178 = Jbz.*q1.*q4.*4.0;
  // 'mass:168' t179 = COM_X.*COM_Y.*Mb.*t5.*4.0;
  // 'mass:169' t180 = Mb.*q2.*q3.*t64.*4.0;
  // 'mass:170' t181 = Jw.*q1.*q4.*t4.*t8.*6.0;
  // 'mass:171' t148 = t84+t85+t86-t108+t124+t125+t126+t127-t177-t178-t179-t180-t181; 
  t148 = (((((((((((t84 + t85) + t86) - t108) + t124) + t125) + t126) + t127) -
             Jby * q2 * q3 * 4.0F) - Jbz * q1 * q4 * 4.0F) - COM_X * COM_Y * Mb *
           t5 * 4.0F) - Mb * q2 * q3 * t64 * 4.0F) - Jw * q1 * q4 * t4 * t8 *
    6.0F;

  // 'mass:172' t153 = Jbx.*t2.*4.0;
  t153 = Jbx * t2 * 4.0F;

  // 'mass:173' t154 = Jby.*t6.*4.0;
  t154 = Jby * t6 * 4.0F;

  // 'mass:174' t155 = Jbz.*t5.*4.0;
  t155 = Jbz * t5 * 4.0F;

  // 'mass:175' t156 = Jw.*t4.*t5.*t8.*6.0;
  t156 = Jw * t4 * t5 * t8 * 6.0F;

  // 'mass:176' t157 = COM_X.*COM_Z.*Mb.*q1.*q3.*8.0;
  t157 = COM_X * COM_Z * Mb * q1 * q3 * 8.0F;

  // 'mass:177' t186 = Jbx.*q2.*q4.*4.0;
  // 'mass:178' t187 = Jby.*q1.*q3.*4.0;
  // 'mass:179' t188 = COM_X.*COM_Z.*Mb.*t3.*4.0;
  // 'mass:180' t189 = Mb.*q2.*q4.*t65.*4.0;
  // 'mass:181' t166 = t66+t67+t68+t69+t90+t91+t92+t93-t94-t136-t186-t187-t188-t189; 
  t166 = ((((((((((((t66 + t67) + t68) + t69) + t90) + t91) + t92) + t93) - t94)
             - t136) - Jbx * q2 * q4 * 4.0F) - Jby * q1 * q3 * 4.0F) - COM_X *
          COM_Z * Mb * t3 * 4.0F) - Mb * q2 * q4 * t65 * 4.0F;

  // 'mass:182' t167 = Jbx.*t6.*4.0;
  // 'mass:183' t168 = Jby.*t2.*4.0;
  // 'mass:184' t169 = Jbz.*t3.*4.0;
  // 'mass:185' t170 = Jw.*t3.*t4.*t8.*6.0;
  // 'mass:186' t171 = t79+t80+t81+t95+t96+t97+t98+t99+t100+t101+t102-t103+t123+t146+t167+t168+t169+t170; 
  t171 = ((((((((((((((((t79 + t80) + t81) + t95) + t96) + t97) + t98) + t99) +
                  t100) + t101) + t102) - t103) + t74) + t76) + Jbx * t6 * 4.0F)
           + Jby * t2 * 4.0F) + Jbz * t3 * 4.0F) + Jw * t3 * t4 * t8 * 6.0F;

  // 'mass:187' t172 = Jbx.*t5.*4.0;
  // 'mass:188' t173 = Jby.*t3.*4.0;
  // 'mass:189' t174 = Jbz.*t2.*4.0;
  // 'mass:190' t175 = Jw.*t2.*t4.*t8.*6.0;
  // 'mass:191' t176 = t78+t82+t83+t95+t96+t97+t98+t99+t100+t121+t122-t123+t145+t157+t172+t173+t174+t175; 
  t176 = ((((((((((((((((t78 + t82) + t83) + t95) + t96) + t97) + t98) + t99) +
                  t100) + t121) + t122) - t74) + t75) + t157) + Jbx * t5 * 4.0F)
           + Jby * t3 * 4.0F) + Jbz * t2 * 4.0F) + Jw * t2 * t4 * t8 * 6.0F;

  // 'mass:192' t182 = t30+t31+t32+t39+t40-t41-t128-t129;
  t136 = ((((((t30 + t31) + t32) + t39) + t40) - t41) - t128) - t129;

  // 'mass:193' t183 = t27+t28+t29+t42+t43-t44-t130-t131;
  t108 = ((((((t27 + t28) + t29) + t42) + t43) - t44) - t130) - t131;

  // 'mass:194' t184 = t35+t36+t37+t38+t45+t46-t47-t132;
  t63 = ((((((t35 + t36) + t37) + t38) + t45) + t46) - t47) - t132;

  // 'mass:195' t185 = t33+t34+t48+t49-t50-t133-t134-t135;
  t88 = ((((((t33 + t34) + t48) + t49) - t50) - t133) - t134) - t135;

  // 'mass:196' t190 = q3.*t77;
  t89 = q3 * t77;

  // 'mass:197' t191 = t78+t79+t80+t81+t82+t83+t95+t98+t99+t121+t122+t141+t142+t143+t144-t145-t146-t147; 
  t76 = ((((((((((((((((t78 + t79) + t80) + t81) + t82) + t83) + t95) + t98) +
                 t99) + t121) + t122) + t141) + t142) + t143) + t144) - t75) -
         t76) - t147;

  // 'mass:198' t192 = q4.*t77;
  t87 = q4 * t77;

  // 'mass:199' t193 = t78+t79+t80+t81+t82+t83+t96+t97+t100+t101+t102+t103+t147+t153+t154+t155+t156-t157; 
  t74 = ((((((((((((((((t78 + t79) + t80) + t81) + t82) + t83) + t96) + t97) +
                 t100) + t101) + t102) + t103) + t147) + t153) + t154) + t155) +
         t156) - t157;

  // 'mass:200' t194 = q3.*t115;
  t75 = q3 * t115;

  // 'mass:201' M = reshape([t8.*t13.*(t14+t16+t18+t20+t22+t23+t24+t25+t26+Jw.*t2.*t3.*t4.*1.8e1+Jw.*t2.*t4.*t5.*6.0+Jw.*t3.*t4.*t6.*6.0+Jw.*t4.*t5.*t6.*1.8e1-Jw.*q1.*q2.*q3.*q4.*t4.*2.4e1).*(1.0./4.0),t12,q2.*t8.*(t35+t36+t37+t38+t45+t46-t47-COM_Y.*Mb.*q4.*t7.*4.0).*(-1.0./2.0)-q3.*t8.*(t27+t28+t29+t42+t43-t44-COM_Y.*Mb.*q1.*t7.*4.0-COM_X.*Mb.*q4.*t7.*4.0).*(1.0./2.0)-q4.*t8.*(t30+t31+t32+t39+t40-t41-COM_Y.*Mb.*q2.*t7.*4.0-COM_Z.*Mb.*q1.*t7.*4.0).*(1.0./2.0)-q1.*t8.*(t33+t34+t48+t49-t50-COM_X.*Mb.*q2.*t7.*4.0-COM_Y.*Mb.*q3.*t7.*4.0-COM_Z.*Mb.*q4.*t7.*4.0).*(1.0./2.0),q1.*t8.*t182.*(-1.0./2.0)+q2.*t8.*t183.*(1.0./2.0)-q3.*t8.*t184.*(1.0./2.0)+q4.*t8.*t185.*(1.0./2.0),q1.*t8.*t183.*(1.0./2.0)+q2.*t8.*t182.*(1.0./2.0)-q3.*t8.*t185.*(1.0./2.0)-q4.*t8.*t184.*(1.0./2.0),0.0,t12,t8.*t13.*(t14+t16+t18+t20+t22+t23+t24+t25+t26+Jw.*t2.*t3.*t4.*6.0+Jw.*t2.*t4.*t5.*1.8e1+Jw.*t3.*t4.*t6.*1.8e1+Jw.*t4.*t5.*t6.*6.0+Jw.*q1.*q2.*q3.*q4.*t4.*2.4e1).*(1.0./4.0),q1.*t8.*t53.*(1.0./2.0)+q2.*t8.*t56.*(1.0./2.0)-q3.*t8.*t59.*(1.0./2.0)-q4.*t8.*t62.*(1.0./2.0),q4.*t8.*t53.*(-1.0./2.0)+q3.*t8.*t56.*(1.0./2.0)+q2.*t8.*t59.*(1.0./2.0)-q1.*t8.*t62.*(1.0./2.0),q3.*t8.*t53.*(1.0./2.0)+q1.*t8.*t59.*(1.0./2.0)+q4.*t8.*t56.*(1.0./2.0)+q2.*t8.*t62.*(1.0./2.0),0.0,t8.*(t35+t36+t37+t38+t45+t46-COM_Y.*Mb.*q4.*t7.*4.0-Jw.*q1.*q2.*q4.*rk.*6.0).*(1.0./2.0),t8.*t56.*(-1.0./2.0),q4.*(t66+t67+t68+t69+t90+t91+t92+t93-Jbx.*q2.*q4.*4.0-Jby.*q1.*q3.*4.0-Mb.*q2.*q4.*t65.*4.0-COM_X.*COM_Z.*Mb.*t3.*4.0-COM_Y.*COM_Z.*Mb.*q2.*q3.*4.0-Jw.*q1.*q3.*t4.*t8.*3.0)-q2.*(t78+t79+t80+t81+t82+t83+t95+t98+t99+t121+t122+t141+t142+t143+t144-COM_X.*COM_Y.*Mb.*q2.*q3.*8.0-COM_X.*COM_Z.*Mb.*q2.*q4.*8.0-COM_Y.*COM_Z.*Mb.*q3.*q4.*8.0)-q1.*t77-q3.*(t84+t85+t86+t124+t125+t126+t127-Jby.*q2.*q3.*4.0-Jbz.*q1.*q4.*4.0-Mb.*q2.*q3.*t64.*4.0-COM_X.*COM_Y.*Mb.*t5.*4.0-COM_X.*COM_Z.*Mb.*q3.*q4.*4.0-Jw.*q1.*q4.*t4.*t8.*6.0),t192+q2.*t148+q1.*t166-q3.*t191,-t190+q1.*t148-q2.*t166-q4.*t191,q1,t8.*(t33+t34+t48+t49-COM_X.*Mb.*q2.*t7.*4.0-COM_Y.*Mb.*q3.*t7.*4.0-COM_Z.*Mb.*q4.*t7.*4.0-Jw.*q1.*q2.*q3.*rk.*6.0).*(-1.0./2.0),t8.*t53.*(1.0./2.0),t194+q2.*t77-q4.*t110+q1.*(t78+t79+t80+t81+t82+t83+t96+t97+t100+t101+t102+t103+t147+t153+t154+t155+t156-COM_X.*COM_Z.*Mb.*q1.*q3.*8.0),t190-q1.*t110-q2.*t115-q4.*t193,t192+q2.*t110-q1.*t115+q3.*t193,q2,t8.*(t30+t31+t32+t39+t40-COM_Y.*Mb.*q2.*t7.*4.0-COM_Z.*Mb.*q1.*t7.*4.0-Jw.*q2.*q3.*q4.*rk.*6.0).*(-1.0./2.0),t8.*t62.*(-1.0./2.0),-q1.*t110+q3.*t120+q4.*t171-q2.*(t66+t67+t68+t69+t90+t91+t92+t93-t94-Jbx.*q2.*q4.*4.0-Jby.*q1.*q3.*4.0-Mb.*q2.*q4.*t65.*4.0-COM_X.*COM_Z.*Mb.*t3.*4.0-Jw.*q1.*q3.*t4.*t8.*3.0),q4.*t110-q2.*t120-q3.*t166+q1.*t171,-q3.*t110-q1.*t120-q4.*t166-q2.*t171,q3,t8.*(t27+t28+t29+t42+t43-COM_Y.*Mb.*q1.*t7.*4.0-COM_X.*Mb.*q4.*t7.*4.0-Jw.*q1.*q3.*q4.*rk.*6.0).*(1.0./2.0),t8.*t59.*(1.0./2.0),-q1.*t115-q4.*t120-q2.*t148-q3.*t176,q4.*t115-q1.*t120-q3.*t148+q2.*t176,-t194+q2.*t120-q4.*t148+q1.*t176,q4],[6,6]); 
  x[0] = t8 * t13 * (((((((((((((t14 + t16) + t18) + t20) + t22) + t23) + t24) +
    t25) + t26) + Jw * t2 * t3 * t4 * 18.0F) + Jw * t2 * t4 * t5 * 6.0F) + Jw *
                       t3 * t4 * t6 * 6.0F) + Jw * t4 * t5 * t6 * 18.0F) - Jw *
                     q1 * q2 * q3 * q4 * t4 * 24.0F) * 0.25F;
  x[1] = t12;
  x[2] = ((q2 * t8 * (((((((t35 + t36) + t37) + t38) + t45) + t46) - t47) -
                      COM_Y * Mb * q4 * t7 * 4.0F) * -0.5F - q3 * t8 *
           (((((((t27 + t28) + t29) + t42) + t43) - t44) - COM_Y * Mb * q1 * t7 *
             4.0F) - COM_X * Mb * q4 * t7 * 4.0F) * 0.5F) - q4 * t8 * (((((((t30
    + t31) + t32) + t39) + t40) - t41) - COM_Y * Mb * q2 * t7 * 4.0F) - COM_Z *
           Mb * q1 * t7 * 4.0F) * 0.5F) - q1 * t8 * (((((((t33 + t34) + t48) +
    t49) - t50) - COM_X * Mb * q2 * t7 * 4.0F) - COM_Y * Mb * q3 * t7 * 4.0F) -
    COM_Z * Mb * q4 * t7 * 4.0F) * 0.5F;
  x[3] = ((q1 * t8 * t136 * -0.5F + q2 * t8 * t108 * 0.5F) - q3 * t8 * t63 *
          0.5F) + q4 * t8 * t88 * 0.5F;
  x[4] = ((q1 * t8 * t108 * 0.5F + q2 * t8 * t136 * 0.5F) - q3 * t8 * t88 * 0.5F)
    - q4 * t8 * t63 * 0.5F;
  x[5] = 0.0F;
  x[6] = t12;
  x[7] = t8 * t13 * (((((((((((((t14 + t16) + t18) + t20) + t22) + t23) + t24) +
    t25) + t26) + Jw * t2 * t3 * t4 * 6.0F) + Jw * t2 * t4 * t5 * 18.0F) + Jw *
                       t3 * t4 * t6 * 18.0F) + Jw * t4 * t5 * t6 * 6.0F) + Jw *
                     q1 * q2 * q3 * q4 * t4 * 24.0F) * 0.25F;
  x[8] = ((q1 * t8 * t53 * 0.5F + q2 * t8 * t56 * 0.5F) - q3 * t8 * t59 * 0.5F)
    - q4 * t8 * t62 * 0.5F;
  x[9] = ((q4 * t8 * t53 * -0.5F + q3 * t8 * t56 * 0.5F) + q2 * t8 * t59 * 0.5F)
    - q1 * t8 * t62 * 0.5F;
  x[10] = ((q3 * t8 * t53 * 0.5F + q1 * t8 * t59 * 0.5F) + q4 * t8 * t56 * 0.5F)
    + q2 * t8 * t62 * 0.5F;
  x[11] = 0.0F;
  x[12] = t8 * (((((((t35 + t36) + t37) + t38) + t45) + t46) - COM_Y * Mb * q4 *
                 t7 * 4.0F) - Jw * q1 * q2 * q4 * rk * 6.0F) * 0.5F;
  x[13] = t8 * t56 * -0.5F;
  x[14] = ((q4 * (((((((((((((t66 + t67) + t68) + t69) + t90) + t91) + t92) +
                        t93) - Jbx * q2 * q4 * 4.0F) - Jby * q1 * q3 * 4.0F) -
                     Mb * q2 * q4 * t65 * 4.0F) - COM_X * COM_Z * Mb * t3 * 4.0F)
                   - COM_Y * COM_Z * Mb * q2 * q3 * 4.0F) - Jw * q1 * q3 * t4 *
                  t8 * 3.0F) - q2 * (((((((((((((((((t78 + t79) + t80) + t81) +
    t82) + t83) + t95) + t98) + t99) + t121) + t122) + t141) + t142) + t143) +
    t144) - COM_X * COM_Y * Mb * q2 * q3 * 8.0F) - COM_X * COM_Z * Mb * q2 * q4 *
              8.0F) - COM_Y * COM_Z * Mb * q3 * q4 * 8.0F)) - q1 * t77) - q3 *
    ((((((((((((t84 + t85) + t86) + t124) + t125) + t126) + t127) - Jby * q2 *
          q3 * 4.0F) - Jbz * q1 * q4 * 4.0F) - Mb * q2 * q3 * t64 * 4.0F) -
       COM_X * COM_Y * Mb * t5 * 4.0F) - COM_X * COM_Z * Mb * q3 * q4 * 4.0F) -
     Jw * q1 * q4 * t4 * t8 * 6.0F);
  x[15] = ((t87 + q2 * t148) + q1 * t166) - q3 * t76;
  x[16] = ((-t89 + q1 * t148) - q2 * t166) - q4 * t76;
  x[17] = q1;
  x[18] = t8 * (((((((t33 + t34) + t48) + t49) - COM_X * Mb * q2 * t7 * 4.0F) -
                  COM_Y * Mb * q3 * t7 * 4.0F) - COM_Z * Mb * q4 * t7 * 4.0F) -
                Jw * q1 * q2 * q3 * rk * 6.0F) * -0.5F;
  x[19] = t8 * t53 * 0.5F;
  x[20] = ((t75 + q2 * t77) - q4 * t110) + q1 * (((((((((((((((((t78 + t79) +
    t80) + t81) + t82) + t83) + t96) + t97) + t100) + t101) + t102) + t103) +
    t147) + t153) + t154) + t155) + t156) - COM_X * COM_Z * Mb * q1 * q3 * 8.0F);
  x[21] = ((t89 - q1 * t110) - q2 * t115) - q4 * t74;
  x[22] = ((t87 + q2 * t110) - q1 * t115) + q3 * t74;
  x[23] = q2;
  x[24] = t8 * (((((((t30 + t31) + t32) + t39) + t40) - COM_Y * Mb * q2 * t7 *
                  4.0F) - COM_Z * Mb * q1 * t7 * 4.0F) - Jw * q2 * q3 * q4 * rk *
                6.0F) * -0.5F;
  x[25] = t8 * t62 * -0.5F;
  x[26] = ((-q1 * t110 + q3 * t120) + q4 * t171) - q2 * (((((((((((((t66 + t67)
    + t68) + t69) + t90) + t91) + t92) + t93) - t94) - Jbx * q2 * q4 * 4.0F) -
    Jby * q1 * q3 * 4.0F) - Mb * q2 * q4 * t65 * 4.0F) - COM_X * COM_Z * Mb * t3
    * 4.0F) - Jw * q1 * q3 * t4 * t8 * 3.0F);
  x[27] = ((q4 * t110 - q2 * t120) - q3 * t166) + q1 * t171;
  x[28] = ((-q3 * t110 - q1 * t120) - q4 * t166) - q2 * t171;
  x[29] = q3;
  x[30] = t8 * (((((((t27 + t28) + t29) + t42) + t43) - COM_Y * Mb * q1 * t7 *
                  4.0F) - COM_X * Mb * q4 * t7 * 4.0F) - Jw * q1 * q3 * q4 * rk *
                6.0F) * 0.5F;
  x[31] = t8 * t59 * 0.5F;
  x[32] = ((-q1 * t115 - q4 * t120) - q2 * t148) - q3 * t176;
  x[33] = ((q4 * t115 - q1 * t120) - q3 * t148) + q2 * t176;
  x[34] = ((-t75 + q2 * t120) - q4 * t148) + q1 * t176;
  x[35] = q4;
  i0 = 0;
  i1 = 0;
  i2 = 0;
  for (i3 = 0; i3 < 36; i3++) {
    M[i1 + 6 * i0] = x[i2];
    i0++;
    if (i0 > 5) {
      i0 = 0;
      i1++;
    }

    i2++;
  }
}

//
// File trailer for mass.cpp
//
// [EOF]
//
