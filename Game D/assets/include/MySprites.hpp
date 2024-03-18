#ifndef MYSPRITES_HPP
#define MYSPRITES_HPP


// 该文件负责存储精灵类对象，用于管理精灵类的图像，arect等属性
// 关于如果存储，详见MYLIBRARY_HPP中关于精灵类的初始化部分
// #if 0 表示后面文件没有用到

#if 1
// res/Tilesmap/
#if 1
//方块
MySprite res_block1("res\\Tilesmap\\block1.png", 131, 147, 10, 1181, 1181);
//按钮
MySprite res_button1("res\\Tilesmap\\button1.png", 50, 50, 10, 500, 500);
//城市
MySprite res_city1("res\\Tilesmap\\city1.png", 8, 8, 24, 192, 120, 1, 4);
//准星
MySprite res_crosshairs("res\\Tilesmap\\crosshairs.png", 138, 137, 20, 2750, 1370);
//emotion表情
MySprite res_emoj1("res\\Tilesmap\\emoj1.png", 32, 38, 10, 320, 114, 1, 4);
//农场路面
MySprite res_farm1("res\\Tilesmap\\farm1.png", 16, 16, 12, 192, 160);
//飞机
MySprite res_plane1("res\\Tilesmap\\plane1.png", 32, 32, 4, 128, 192);
//勋章等级
MySprite res_rankGolden("res\\Tilesmap\\rankGolden.png", 128, 128, 13, 1664, 768, 2);
MySprite res_rankGreen("res\\Tilesmap\\rankGreen.png", 128, 128, 13, 1664, 768, 2);
MySprite res_rankRed("res\\Tilesmap\\rankRed", 128, 128, 13, 1664, 768, 2);
MySprite res_rankSilver("res\\Tilesmap\\rankSilver", 128, 128, 13, 1664, 768, 2);
//铭文
MySprite res_runeBlue1("res\\Tilesmap\\runeBlue1.png", 54, 90, 7, 378, 450);
MySprite res_runeBlue2("res\\Tilesmap\\runeBlue2.png", 54, 60, 6, 324, 360);
//海船
MySprite res_ship1("res\\Tilesmap\\ship1.png", 16, 16, 17, 272, 128);
MySprite res_ship2("res\\Tilesmap\\ship2.png", 16, 16, 17, 272, 128);
MySprite res_ship3("res\\Tilesmap\\ship3.png", 16, 16, 17, 272, 128);
//城镇
MySprite res_town1("res\\Tilesmap\\town1.png", 16, 16, 12, 192, 176);
//交通工具
MySprite res_vehicle1("res\\Tilesmap\\vehicle1.png", 16, 16, 17, 288, 176);
#endif 

//外星小人 //alienPlayer
#if 1
MySprite res_alien0("res\\Tilesmap\\alienPlayer\\alien0.png", 0 ,0, 1, 128, 256, 6, 1);
MySprite res_alien1("res\\Tilesmap\\alienPlayer\\alien1.png", 0, 0, 1, 128, 256, 6, 1);
MySprite res_alien2("res\\Tilesmap\\alienPlayer\\alien2.png", 0, 0, 1, 128, 256, 6, 1);
MySprite res_alien3("res\\Tilesmap\\alienPlayer\\alien3.png", 0, 0, 1, 128, 256, 6, 1);
MySprite res_alien4("res\\Tilesmap\\alienPlayer\\alien4.png", 0, 0, 1, 128, 256, 6, 1);
MySprite res_alien5("res\\Tilesmap\\alienPlayer\\alien5.png", 0, 0, 1, 128, 256, 6, 1);
MySprite res_alien6("res\\Tilesmap\\alienPlayer\\alien6.png", 0, 0, 1, 128, 256, 6, 1);
MySprite res_alien7("res\\Tilesmap\\alienPlayer\\alien7.png", 0, 0, 1, 128, 256, 6, 1);
MySprite res_alien8("res\\Tilesmap\\alienPlayer\\alien8.png", 0, 0, 1, 128, 256, 6, 1);
MySprite res_alien9("res\\Tilesmap\\alienPlayer\\alien9.png", 0, 0, 1, 128, 256, 6, 1);
MySprite res_alien10("res\\Tilesmap\\alienPlayer\\alien0.png", 0, 0, 1, 128, 256, 4, 1);
MySprite res_alien11("res\\Tilesmap\\alienPlayer\\alien1.png", 0, 0, 1, 128, 256, 4, 1);
MySprite res_alien12("res\\Tilesmap\\alienPlayer\\alien2.png", 0, 0, 1, 128, 256, 4, 1);
MySprite res_alien13("res\\Tilesmap\\alienPlayer\\alien3.png", 0, 0, 1, 128, 256, 4, 1);
MySprite res_alien14("res\\Tilesmap\\alienPlayer\\alien4.png", 0, 0, 1, 128, 256, 4, 1);
MySprite res_alien15("res\\Tilesmap\\alienPlayer\\alien5.png", 0, 0, 1, 128, 256, 4, 1);
MySprite res_alien16("res\\Tilesmap\\alienPlayer\\alien6.png", 0, 0, 1, 128, 256, 4, 1);
MySprite res_alien17("res\\Tilesmap\\alienPlayer\\alien7.png", 0, 0, 1, 128, 256, 4, 1);
MySprite res_alien18("res\\Tilesmap\\alienPlayer\\alien8.png", 0, 0, 1, 128, 256, 4, 1);
MySprite res_alien19("res\\Tilesmap\\alienPlayer\\alien9.png", 0, 0, 1, 128, 256, 4, 1);
MySprite* Res_alien[20] = { &res_alien0 ,&res_alien1 , &res_alien2 , &res_alien3 ,&res_alien4 ,
							&res_alien5 ,&res_alien6 ,&res_alien7 ,&res_alien8 ,&res_alien9 ,
							& res_alien10 ,& res_alien11 ,& res_alien12 ,& res_alien13 ,& res_alien14 ,
							& res_alien15 ,& res_alien16 ,& res_alien17 ,& res_alien18 ,& res_alien19 };
#endif
//动物头 Animal Round
#if 1
MySprite res_elephant(8,1,"res\\Tilesmap\\Animal Round\\elephant.png");
MySprite res_giraffe(8, 1, "res\\Tilesmap\\Animal Round\\giraffe.png");
MySprite res_hippo(8, 1, "res\\Tilesmap\\Animal Round\\hippo.png");
MySprite res_monkey(8, 1, "res\\Tilesmap\\Animal Round\\monkey.png");
MySprite res_panda(8, 1, "res\\Tilesmap\\Animal Round\\panda.png");
MySprite res_parrot(8, 1, "res\\Tilesmap\\Animal Round\\parrot.png");
MySprite res_penguin(8, 1, "res\\Tilesmap\\Animal Round\\penguin.png");
MySprite res_pig(8, 1, "res\\Tilesmap\\Animal Round\\pig.png");
MySprite res_rabbit(8, 1, "res\\Tilesmap\\Animal Round\\rabbit.png");
MySprite res_snake(8, 1, "res\\Tilesmap\\Animal Round\\snake.png");
MySprite* Res_animal[10] = {&res_elephant ,&res_giraffe ,&res_hippo ,&res_monkey ,&res_panda
							,&res_parrot ,&res_penguin ,&res_pig ,&res_rabbit ,&res_snake };
#endif 
//按键 line-dark
#if 0
MySprite res_lineDark00("res\\Tilesmap\\Animal Round\\lineDark00.png");
MySprite res_lineDark01("res\\Tilesmap\\Animal Round\\lineDark01.png");
MySprite res_lineDark02("res\\Tilesmap\\Animal Round\\lineDark02.png");
MySprite res_lineDark03("res\\Tilesmap\\Animal Round\\lineDark03.png");
MySprite res_lineDark04("res\\Tilesmap\\Animal Round\\lineDark04.png");
MySprite res_lineDark05("res\\Tilesmap\\Animal Round\\lineDark05.png");
MySprite res_lineDark06("res\\Tilesmap\\Animal Round\\lineDark06.png");
MySprite res_lineDark07("res\\Tilesmap\\Animal Round\\lineDark07.png");
MySprite res_lineDark08("res\\Tilesmap\\Animal Round\\lineDark08.png");
MySprite res_lineDark09("res\\Tilesmap\\Animal Round\\lineDark09.png");
MySprite res_lineDark10("res\\Tilesmap\\Animal Round\\lineDark10.png");
MySprite res_lineDark11("res\\Tilesmap\\Animal Round\\lineDark11.png");
MySprite res_lineDark12("res\\Tilesmap\\Animal Round\\lineDark12.png");
MySprite res_lineDark13("res\\Tilesmap\\Animal Round\\lineDark13.png");
MySprite res_lineDark14("res\\Tilesmap\\Animal Round\\lineDark14.png");
MySprite res_lineDark15("res\\Tilesmap\\Animal Round\\lineDark15.png");
MySprite res_lineDark16("res\\Tilesmap\\Animal Round\\lineDark16.png");
MySprite res_lineDark17("res\\Tilesmap\\Animal Round\\lineDark17.png");
MySprite res_lineDark18("res\\Tilesmap\\Animal Round\\lineDark18.png");
MySprite res_lineDark19("res\\Tilesmap\\Animal Round\\lineDark19.png");
MySprite res_lineDark20("res\\Tilesmap\\Animal Round\\lineDark20.png");
MySprite res_lineDark21("res\\Tilesmap\\Animal Round\\lineDark21.png");
MySprite res_lineDark22("res\\Tilesmap\\Animal Round\\lineDark22.png");
MySprite res_lineDark23("res\\Tilesmap\\Animal Round\\lineDark23.png");
MySprite res_lineDark24("res\\Tilesmap\\Animal Round\\lineDark24.png");
MySprite res_lineDark25("res\\Tilesmap\\Animal Round\\lineDark25.png");
MySprite res_lineDark26("res\\Tilesmap\\Animal Round\\lineDark26.png");
MySprite res_lineDark27("res\\Tilesmap\\Animal Round\\lineDark27.png");
MySprite res_lineDark28("res\\Tilesmap\\Animal Round\\lineDark28.png");
MySprite res_lineDark29("res\\Tilesmap\\Animal Round\\lineDark29.png");
MySprite res_lineDark30("res\\Tilesmap\\Animal Round\\lineDark30.png");
MySprite res_lineDark31("res\\Tilesmap\\Animal Round\\lineDark31.png");
MySprite res_lineDark32("res\\Tilesmap\\Animal Round\\lineDark32.png");
MySprite res_lineDark33("res\\Tilesmap\\Animal Round\\lineDark33.png");
MySprite res_lineDark34("res\\Tilesmap\\Animal Round\\lineDark34.png");
MySprite res_lineDark35("res\\Tilesmap\\Animal Round\\lineDark35.png");
MySprite res_lineDark36("res\\Tilesmap\\Animal Round\\lineDark36.png");
MySprite res_lineDark37("res\\Tilesmap\\Animal Round\\lineDark37.png");
MySprite res_lineDark38("res\\Tilesmap\\Animal Round\\lineDark38.png");
MySprite res_lineDark39("res\\Tilesmap\\Animal Round\\lineDark39.png");
MySprite res_lineDark40("res\\Tilesmap\\Animal Round\\lineDark40.png");
MySprite res_lineDark41("res\\Tilesmap\\Animal Round\\lineDark41.png");
MySprite res_lineDark42("res\\Tilesmap\\Animal Round\\lineDark42.png");
MySprite res_lineDark43("res\\Tilesmap\\Animal Round\\lineDark43.png");
MySprite res_lineDark44("res\\Tilesmap\\Animal Round\\lineDark44.png");
MySprite res_lineDark45("res\\Tilesmap\\Animal Round\\lineDark45.png");
MySprite res_lineDark46("res\\Tilesmap\\Animal Round\\lineDark46.png");
MySprite res_lineDark47("res\\Tilesmap\\Animal Round\\lineDark47.png");
MySprite res_lineDark48("res\\Tilesmap\\Animal Round\\lineDark48.png");
MySprite res_lineDark49("res\\Tilesmap\\Animal Round\\lineDark49.png");
MySprite *Res_lineDark[50] = { &res_lineDark00 ,&res_lineDark01 , &res_lineDark02 , &res_lineDark03 ,&res_lineDark04 ,
							&res_lineDark05 ,&res_lineDark06 ,&res_lineDark07 ,&res_lineDark08 ,&res_lineDark09 ,
							&res_lineDark10 ,&res_lineDark11 ,&res_lineDark12 ,&res_lineDark13 ,&res_lineDark14 ,
							&res_lineDark15 ,&res_lineDark16 ,&res_lineDark17 ,&res_lineDark18 ,&res_lineDark19 ,
							&res_lineDark20 ,&res_lineDark21 ,&res_lineDark22 ,&res_lineDark23 ,&res_lineDark24 ,
							&res_lineDark25 ,&res_lineDark26 ,&res_lineDark27 ,&res_lineDark28 ,&res_lineDark29 ,
							&res_lineDark30 ,&res_lineDark31 ,&res_lineDark32 ,&res_lineDark33 ,&res_lineDark34 ,
							&res_lineDark35 ,&res_lineDark36 ,&res_lineDark37 ,&res_lineDark38 ,&res_lineDark39 ,
							&res_lineDark40 ,&res_lineDark41 ,&res_lineDark42 ,&res_lineDark43 ,&res_lineDark44 ,
							&res_lineDark45 ,&res_lineDark46 ,&res_lineDark47 ,&res_lineDark48 ,&res_lineDark49 };
#endif 
//星球 Planets
#if 1
MySprite res_planet00(10,1,"res\\Tilesmap\\Planets\\planet00.png");
MySprite res_planet01(10, 1, "res\\Tilesmap\\Planets\\planet01.png");
MySprite res_planet02(10, 1, "res\\Tilesmap\\Planets\\planet02.png");
MySprite res_planet03(10, 1, "res\\Tilesmap\\Planets\\planet03.png");
MySprite res_planet04(10, 1, "res\\Tilesmap\\Planets\\planet04.png");
MySprite res_planet05(10, 1, "res\\Tilesmap\\Planets\\planet05.png");
MySprite res_planet06(10, 1, "res\\Tilesmap\\Planets\\planet06.png");
MySprite res_planet07(10, 1, "res\\Tilesmap\\Planets\\planet07.png");
MySprite res_planet08(10, 1, "res\\Tilesmap\\Planets\\planet08.png");
MySprite res_planet09(10, 1, "res\\Tilesmap\\Planets\\planet09.png");
MySprite* Res_planet[10] = { &res_planet00 ,&res_planet01 ,&res_planet02 ,&res_planet03 ,&res_planet04 ,
							&res_planet05 ,&res_planet06 ,&res_planet07 ,&res_planet08 ,&res_planet09 };
#endif 
//油溅 Spill-Double
#if 0
MySprite res_splat00("res\\Tilesmap\\Spill-Double\\splat00.png");
MySprite res_splat01("res\\Tilesmap\\Spill-Double\\splat01.png");
MySprite res_splat02("res\\Tilesmap\\Spill-Double\\splat02.png");
MySprite res_splat03("res\\Tilesmap\\Spill-Double\\splat03.png");
MySprite res_splat04("res\\Tilesmap\\Spill-Double\\splat04.png");
MySprite res_splat05("res\\Tilesmap\\Spill-Double\\splat05.png");
MySprite res_splat06("res\\Tilesmap\\Spill-Double\\splat06.png");
MySprite res_splat07("res\\Tilesmap\\Spill-Double\\splat07.png");
MySprite res_splat08("res\\Tilesmap\\Spill-Double\\splat08.png");
MySprite res_splat09("res\\Tilesmap\\Spill-Double\\splat09.png");
MySprite res_splat10("res\\Tilesmap\\Spill-Double\\splat10.png");
MySprite res_splat11("res\\Tilesmap\\Spill-Double\\splat11.png");
MySprite res_splat12("res\\Tilesmap\\Spill-Double\\splat12.png");
MySprite res_splat13("res\\Tilesmap\\Spill-Double\\splat13.png");
MySprite res_splat14("res\\Tilesmap\\Spill-Double\\splat14.png");
MySprite res_splat15("res\\Tilesmap\\Spill-Double\\splat15.png");
MySprite res_splat16("res\\Tilesmap\\Spill-Double\\splat16.png");
MySprite res_splat17("res\\Tilesmap\\Spill-Double\\splat17.png");
MySprite res_splat18("res\\Tilesmap\\Spill-Double\\splat18.png");
MySprite res_splat19("res\\Tilesmap\\Spill-Double\\splat19.png");
MySprite res_splat20("res\\Tilesmap\\Spill-Double\\splat20.png");
MySprite res_splat21("res\\Tilesmap\\Spill-Double\\splat21.png");
MySprite res_splat22("res\\Tilesmap\\Spill-Double\\splat22.png");
MySprite res_splat23("res\\Tilesmap\\Spill-Double\\splat23.png");
MySprite res_splat24("res\\Tilesmap\\Spill-Double\\splat24.png");
MySprite res_splat25("res\\Tilesmap\\Spill-Double\\splat25.png");
MySprite res_splat26("res\\Tilesmap\\Spill-Double\\splat26.png");
MySprite res_splat27("res\\Tilesmap\\Spill-Double\\splat27.png");
MySprite res_splat28("res\\Tilesmap\\Spill-Double\\splat28.png");
MySprite res_splat29("res\\Tilesmap\\Spill-Double\\splat29.png");
MySprite res_splat30("res\\Tilesmap\\Spill-Double\\splat30.png");
MySprite res_splat31("res\\Tilesmap\\Spill-Double\\splat31.png");
MySprite res_splat32("res\\Tilesmap\\Spill-Double\\splat32.png");
MySprite res_splat33("res\\Tilesmap\\Spill-Double\\splat33.png");
MySprite res_splat34("res\\Tilesmap\\Spill-Double\\splat34.png");
MySprite res_splat35("res\\Tilesmap\\Spill-Double\\splat35.png");
MySprite* Res_splat[36] = { &res_splat00 ,&res_splat01 ,&res_splat02 ,&res_splat03 ,&res_splat04 ,&res_splat05 ,
						&res_splat06 ,&res_splat07 ,&res_splat08 ,&res_splat09 ,&res_splat10 ,&res_splat11,
						&res_splat12,& res_splat13,& res_splat14,& res_splat15,& res_splat16,& res_splat17,
						&res_splat18,& res_splat19,& res_splat20,& res_splat21,& res_splat22,& res_splat23,
						&res_splat24,& res_splat25,& res_splat26,& res_splat27,& res_splat28,& res_splat29,
						&res_splat30,& res_splat31,& res_splat32,& res_splat33,& res_splat34,& res_splat35};
#endif
//坦克 tanks
#if 1
MySprite res_tanks00(2, 1, "res\\Tilesmap\\tanks\\tanks00.png");
MySprite res_tanks01(2, 1, "res\\Tilesmap\\tanks\\tanks01.png");
MySprite res_tanks02(2, 1, "res\\Tilesmap\\tanks\\tanks02.png");
MySprite res_tanks03(2, 1, "res\\Tilesmap\\tanks\\tanks03.png");
MySprite res_tanks04(2, 1, "res\\Tilesmap\\tanks\\tanks04.png");
MySprite res_tanks05(2, 1, "res\\Tilesmap\\tanks\\tanks05.png");
MySprite res_tanks06(2, 1, "res\\Tilesmap\\tanks\\tanks06.png");
MySprite res_tanks07(2, 1, "res\\Tilesmap\\tanks\\tanks07.png");
MySprite res_tanks08(2, 1, "res\\Tilesmap\\tanks\\tanks08.png");
MySprite res_tanks09(2, 1, "res\\Tilesmap\\tanks\\tanks09.png");
MySprite res_tanks10(2, 1, "res\\Tilesmap\\tanks\\tanks10.png");
MySprite res_tanks11(2, 1, "res\\Tilesmap\\tanks\\tanks11.png");
MySprite res_tanks12(2, 1, "res\\Tilesmap\\tanks\\tanks12.png");
MySprite res_tanks13(2, 1, "res\\Tilesmap\\tanks\\tanks13.png");
MySprite res_tanks14(2, 1, "res\\Tilesmap\\tanks\\tanks14.png");
MySprite res_tanks15(2, 1, "res\\Tilesmap\\tanks\\tanks15.png");
MySprite res_tanks16(2, 1, "res\\Tilesmap\\tanks\\tanks16.png");
MySprite res_tanks17(2, 1, "res\\Tilesmap\\tanks\\tanks17.png");
MySprite res_tanks18(2, 1, "res\\Tilesmap\\tanks\\tanks18.png");
MySprite res_tanks19(2, 1, "res\\Tilesmap\\tanks\\tanks19.png");
MySprite res_tanks20(2, 1, "res\\Tilesmap\\tanks\\tanks20.png");
MySprite res_tanks21(2, 1, "res\\Tilesmap\\tanks\\tanks21.png");
MySprite res_tanks22(2, 1, "res\\Tilesmap\\tanks\\tanks22.png");
MySprite res_tanks23(2, 1, "res\\Tilesmap\\tanks\\tanks23.png");
MySprite res_tanks24(2, 1, "res\\Tilesmap\\tanks\\tanks24.png");
MySprite res_tanks25(2, 1, "res\\Tilesmap\\tanks\\tanks25.png");
MySprite res_tanks26(2, 1, "res\\Tilesmap\\tanks\\tanks26.png");
MySprite res_tanks27(2, 1, "res\\Tilesmap\\tanks\\tanks27.png");
MySprite res_tanks28(2, 1, "res\\Tilesmap\\tanks\\tanks28.png");
MySprite res_tanks29(2, 1, "res\\Tilesmap\\tanks\\tanks29.png");
MySprite res_tanks30(2, 1, "res\\Tilesmap\\tanks\\tanks30.png");
MySprite res_tanks31(2, 1, "res\\Tilesmap\\tanks\\tanks31.png");
MySprite res_tanks32(2, 1, "res\\Tilesmap\\tanks\\tanks32.png");
MySprite res_tanks33(2, 1, "res\\Tilesmap\\tanks\\tanks33.png");
MySprite res_tanks34(2, 1, "res\\Tilesmap\\tanks\\tanks34.png");
MySprite res_tanks35(2, 1, "res\\Tilesmap\\tanks\\tanks35.png");
MySprite res_tanks36(2, 1, "res\\Tilesmap\\tanks\\tanks36.png");
MySprite res_tanks37(2, 1, "res\\Tilesmap\\tanks\\tanks37.png");
MySprite res_tanks38(2, 1, "res\\Tilesmap\\tanks\\tanks38.png");
MySprite res_tanks39(2, 1, "res\\Tilesmap\\tanks\\tanks39.png");
MySprite* Res_tanks[40] = { &res_tanks00 ,&res_tanks01 ,&res_tanks02 ,&res_tanks03 ,&res_tanks04 ,&res_tanks05 ,
						&res_tanks06 ,&res_tanks07 ,&res_tanks08 ,&res_tanks09 ,&res_tanks10 ,&res_tanks11,
						&res_tanks12,&res_tanks13,&res_tanks14,&res_tanks15,&res_tanks16,&res_tanks17,
						&res_tanks18,&res_tanks19,&res_tanks20,&res_tanks21,&res_tanks22,&res_tanks23,
						&res_tanks24,&res_tanks25,&res_tanks26,&res_tanks27,&res_tanks28,&res_tanks29,
						&res_tanks30,&res_tanks31,&res_tanks32,&res_tanks33,&res_tanks34,&res_tanks35,
						& res_tanks36,& res_tanks37,& res_tanks38,& res_tanks39 };
MySprite res_tank_bullet0(2, 1, "res\\Tilesmap\\tanks\\tank_bullet0.png");
MySprite res_tank_bullet1(2, 1, "res\\Tilesmap\\tanks\\tank_bullet1.png");
MySprite res_tank_bullet2(2, 1, "res\\Tilesmap\\tanks\\tank_bullet2.png");
MySprite res_tank_bullet3(2, 1, "res\\Tilesmap\\tanks\\tank_bullet3.png");
MySprite* Res_tanks_bullet[4] = { &res_tank_bullet0 ,&res_tank_bullet1 ,&res_tank_bullet2 ,&res_tank_bullet3 };
#endif
//油
#if 0
#endif
//树&建筑 Tree&bulid
#if 0
#if 1
MySprite res_bush0("res\\Tilesmap\\Tree&bulid\\bush0.png");
MySprite res_bush1("res\\Tilesmap\\Tree&bulid\\bush1.png");
MySprite res_bush2("res\\Tilesmap\\Tree&bulid\\bush2.png");
MySprite res_bush3("res\\Tilesmap\\Tree&bulid\\bush3.png");
MySprite res_bush4("res\\Tilesmap\\Tree&bulid\\bush4.png");
MySprite res_bush5("res\\Tilesmap\\Tree&bulid\\bush5.png");
MySprite res_bush6("res\\Tilesmap\\Tree&bulid\\bush6.png");
MySprite res_bush7("res\\Tilesmap\\Tree&bulid\\bush7.png");
MySprite res_bush8("res\\Tilesmap\\Tree&bulid\\bush8.png");
MySprite res_bush9("res\\Tilesmap\\Tree&bulid\\bush9.png");
MySprite res_bush10("res\\Tilesmap\\Tree&bulid\\bush10.png");
MySprite res_bush11("res\\Tilesmap\\Tree&bulid\\bush11.png");
MySprite res_bush12("res\\Tilesmap\\Tree&bulid\\bush12.png");
MySprite res_bush13("res\\Tilesmap\\Tree&bulid\\bush13.png");
MySprite res_bush14("res\\Tilesmap\\Tree&bulid\\bush14.png");
MySprite* Res_bush[15] = { &res_bush0 ,&res_bush1 , &res_bush2 , &res_bush3 , &res_bush4 ,
						&res_bush5 ,&res_bush6 ,&res_bush7 ,&res_bush8 ,&res_bush9 ,
						&res_bush10 ,&res_bush11 ,&res_bush12 ,&res_bush13 ,&res_bush14 };
#endif //灌木
#if 1
MySprite res_castle0("res\\Tilesmap\\Tree&bulid\\castle0.png");
MySprite res_castle1("res\\Tilesmap\\Tree&bulid\\castle1.png");
MySprite res_castle2("res\\Tilesmap\\Tree&bulid\\castle2.png");
MySprite res_castle3("res\\Tilesmap\\Tree&bulid\\castle3.png");
MySprite* Res_castle[4] = { &res_castle0 ,&res_castle1 , &res_castle2 , &res_castle3 };
#endif //城堡
#if 1
MySprite res_cloud0("res\\Tilesmap\\Tree&bulid\\cloud0.png");
MySprite res_cloud1("res\\Tilesmap\\Tree&bulid\\cloud1.png");
MySprite res_cloud2("res\\Tilesmap\\Tree&bulid\\cloud2.png");
MySprite res_cloud3("res\\Tilesmap\\Tree&bulid\\cloud3.png");
MySprite res_cloud4("res\\Tilesmap\\Tree&bulid\\cloud4.png");
MySprite res_cloud5("res\\Tilesmap\\Tree&bulid\\cloud5.png");
MySprite res_cloud6("res\\Tilesmap\\Tree&bulid\\cloud6.png");
MySprite res_cloud7("res\\Tilesmap\\Tree&bulid\\cloud7.png");
MySprite* Res_cloud[8] = { &res_cloud0 ,&res_cloud1 , &res_cloud2 , &res_cloud3 , &res_cloud4 ,
						&res_cloud5 ,&res_cloud6 ,&res_cloud7 };
#endif //云
#if 1
MySprite res_fence0("res\\Tilesmap\\Tree&bulid\\fence0.png");
MySprite res_fence1("res\\Tilesmap\\Tree&bulid\\fence1.png");
MySprite* Res_fence[2] = { &res_fence0 ,&res_fence1 };
#endif //栅栏
#if 1
MySprite res_house0("res\\Tilesmap\\Tree&bulid\\house0.png");
MySprite res_house1("res\\Tilesmap\\Tree&bulid\\house1.png");
MySprite res_house2("res\\Tilesmap\\Tree&bulid\\house2.png");
MySprite res_house3("res\\Tilesmap\\Tree&bulid\\house3.png");
MySprite res_house4("res\\Tilesmap\\Tree&bulid\\house4.png");
MySprite res_house5("res\\Tilesmap\\Tree&bulid\\house5.png");
MySprite res_house6("res\\Tilesmap\\Tree&bulid\\house6.png");
MySprite res_house7("res\\Tilesmap\\Tree&bulid\\house7.png");
MySprite* Res_house[8] = { &res_house0 ,&res_house1 , &res_house2 , &res_house3 , &res_house4 ,
						&res_house5 ,&res_house6 ,&res_house7 };
#endif //房子
#if 1
MySprite res_pyramid0("res\\Tilesmap\\Tree&bulid\\pyramid0.png");
MySprite res_pyramid1("res\\Tilesmap\\Tree&bulid\\pyramid1.png");
MySprite* Res_pyramid[2] = { &res_pyramid0 ,&res_pyramid1 };
#endif //金字塔
#if 1
MySprite res_tower0("res\\Tilesmap\\Tree&bulid\\tower0.png");
MySprite res_tower1("res\\Tilesmap\\Tree&bulid\\tower1.png");
MySprite res_tower2("res\\Tilesmap\\Tree&bulid\\tower2.png");
MySprite res_tower3("res\\Tilesmap\\Tree&bulid\\tower3.png");
MySprite* Res_tower[4] = { &res_tower0 ,&res_tower1 , &res_tower2 , &res_tower3 };
#endif //塔
#if 1
MySprite res_tree0("res\\Tilesmap\\Tree&bulid\\tree0.png");
MySprite res_tree1("res\\Tilesmap\\Tree&bulid\\tree1.png");
MySprite res_tree2("res\\Tilesmap\\Tree&bulid\\tree2.png");
MySprite res_tree3("res\\Tilesmap\\Tree&bulid\\tree3.png");
MySprite res_tree4("res\\Tilesmap\\Tree&bulid\\tree4.png");
MySprite res_tree5("res\\Tilesmap\\Tree&bulid\\tree5.png");
MySprite res_tree6("res\\Tilesmap\\Tree&bulid\\tree6.png");
MySprite res_tree7("res\\Tilesmap\\Tree&bulid\\tree7.png");
MySprite res_tree8("res\\Tilesmap\\Tree&bulid\\tree8.png");
MySprite res_tree9("res\\Tilesmap\\Tree&bulid\\tree9.png");
MySprite res_tree10("res\\Tilesmap\\Tree&bulid\\tree10.png");
MySprite res_tree11("res\\Tilesmap\\Tree&bulid\\tree11.png");
MySprite res_tree12("res\\Tilesmap\\Tree&bulid\\tree12.png");
MySprite res_tree13("res\\Tilesmap\\Tree&bulid\\tree13.png");
MySprite res_tree14("res\\Tilesmap\\Tree&bulid\\tree14.png");
MySprite res_tree15("res\\Tilesmap\\Tree&bulid\\tree15.png");
MySprite res_tree16("res\\Tilesmap\\Tree&bulid\\tree16.png");
MySprite res_tree17("res\\Tilesmap\\Tree&bulid\\tree17.png");
MySprite res_tree18("res\\Tilesmap\\Tree&bulid\\tree18.png");
MySprite res_tree19("res\\Tilesmap\\Tree&bulid\\tree19.png");
MySprite res_tree20("res\\Tilesmap\\Tree&bulid\\tree20.png");
MySprite res_tree21("res\\Tilesmap\\Tree&bulid\\tree21.png");
MySprite res_tree22("res\\Tilesmap\\Tree&bulid\\tree22.png");
MySprite* Res_tree[23] = { &res_tree0 ,&res_tree1 ,&res_tree2 ,&res_tree3 ,&res_tree4 ,&res_tree5 ,
						&res_tree6 ,&res_tree7 ,&res_tree8 ,&res_tree9 ,&res_tree10 ,&res_tree11,
						&res_tree12,&res_tree13,&res_tree14,&res_tree15,&res_tree16,&res_tree17,
						&res_tree18,&res_tree19,&res_tree20,&res_tree21,&res_tree22 };
#endif //树
#endif
//黄油 yellow-paintDouble
#if 0
MySprite res_paint_adown("res\\Tilesmap\\yellow-paintDouble\\paint_adown.png");
MySprite res_paint_aleft("res\\Tilesmap\\yellow-paintDouble\\paint_aleft.png");
MySprite res_paint_aright("res\\Tilesmap\\yellow-paintDouble\\paint_aright.png");
MySprite res_paint_aup("res\\Tilesmap\\yellow-paintDouble\\paint_aup.png");
MySprite res_paint_ca("res\\Tilesmap\\yellow-paintDouble\\paint_ca.png");
MySprite res_paint_cb("res\\Tilesmap\\yellow-paintDouble\\paint_cb.png");
MySprite res_paint_da("res\\Tilesmap\\yellow-paintDouble\\paint_da.png");
MySprite res_paint_db("res\\Tilesmap\\yellow-paintDouble\\paint_db.png");
MySprite res_paint_dc("res\\Tilesmap\\yellow-paintDouble\\paint_dc.png");
MySprite res_paint_sa("res\\Tilesmap\\yellow-paintDouble\\paint_sa.png");
MySprite res_paint_sb("res\\Tilesmap\\yellow-paintDouble\\paint_sb.png");
MySprite res_paint_sc("res\\Tilesmap\\yellow-paintDouble\\paint_sc.png");
MySprite res_paint_sd("res\\Tilesmap\\yellow-paintDouble\\paint_sd.png");
MySprite *Res_yellowpaint[13] = {&res_paint_adown,&res_paint_aleft,&res_paint_aright,&res_paint_aup,
				&res_paint_ca,& res_paint_cb,& res_paint_da,& res_paint_db,& res_paint_dc,
				& res_paint_sa ,& res_paint_sb ,& res_paint_sc ,& res_paint_sd };
#endif
//主播
#if 1
MySprite res_bg_stream(2, 1, "res//CTJ000//bg_stream.png");
MySprite res_ctj0(1, 1, "res//CTJ000//0.png");
MySprite res_ctj1(1, 1,"res//CTJ000//1.png");
MySprite res_ctj2(1, 1, "res//CTJ000//2.png");
MySprite res_ctj3(1, 1, "res//CTJ000//3.png");
MySprite res_ctj4(1, 1, "res//CTJ000//4.png");
MySprite res_ctj5(1, 1, "res//CTJ000//5.png");
MySprite res_ctj6(1, 1, "res//CTJ000//6.png");
MySprite res_ctj7(1, 1, "res//CTJ000//7.png");
MySprite res_ctj8(1, 1, "res//CTJ000//8.png");
MySprite res_ctj9(1, 1, "res//CTJ000//9.png");
MySprite res_ctj10(1, 1, "res//CTJ000//10.png");
MySprite res_ctj11(1, 1, "res//CTJ000//11.png");
MySprite res_ctj12(1, 1, "res//CTJ000//12.png");
MySprite res_ctj13(1, 1, "res//CTJ000//13.png");
MySprite res_ctj14(1, 1, "res//CTJ000//14.png");
MySprite res_ctj15(1, 1, "res//CTJ000//15.png");
MySprite res_ctj16(1, 1, "res//CTJ000//16.png");
MySprite res_ctj17(1, 1, "res//CTJ000//17.png");
MySprite res_ctj18(1, 1, "res//CTJ000//18.png");
MySprite res_ctj19(1, 1, "res//CTJ000//19.png");
MySprite res_ctj20(1, 1, "res//CTJ000//20.png");
MySprite res_ctj21(1, 1, "res//CTJ000//21.png");

MySprite res_ctj22(1, 1, "res//CTJ000//22.png");
MySprite res_ctj23(1, 1, "res//CTJ000//23.png");
MySprite res_ctj24(1, 1, "res//CTJ000//24.png");
MySprite res_ctj25(1, 1, "res//CTJ000//25.png");
MySprite res_ctj26(1, 1, "res//CTJ000//26.png");
MySprite res_ctj27(1, 1, "res//CTJ000//27.png");
MySprite res_ctj28(1, 1, "res//CTJ000//28.png");
MySprite res_ctj29(1, 1, "res//CTJ000//29.png");
MySprite res_ctj30(1, 1, "res//CTJ000//30.png");
MySprite res_ctj31(1, 1, "res//CTJ000//31.png");
MySprite res_ctj32(1, 1, "res//CTJ000//32.png");
MySprite res_ctj33(1, 1, "res//CTJ000//33.png");
MySprite res_ctj34(1, 1, "res//CTJ000//34.png");
MySprite res_ctj35(1, 1, "res//CTJ000//35.png");
MySprite res_ctj36(1, 1, "res//CTJ000//36.png");
MySprite res_ctj37(1, 1, "res//CTJ000//37.png");
MySprite res_ctj38(1, 1, "res//CTJ000//38.png");
MySprite res_ctj39(1, 1, "res//CTJ000//39.png");
MySprite res_ctj40(1, 1, "res//CTJ000//40.png");
MySprite res_ctj41(1, 1, "res//CTJ000//41.png");

MySprite res_ctj42(1, 1, "res//CTJ000//42.png");
MySprite res_ctj43(1, 1, "res//CTJ000//43.png");
MySprite res_ctj44(1, 1, "res//CTJ000//44.png");
MySprite res_ctj45(1, 1, "res//CTJ000//45.png");
MySprite res_ctj46(1, 1, "res//CTJ000//46.png");
MySprite res_ctj47(1, 1, "res//CTJ000//47.png");
MySprite res_ctj48(1, 1, "res//CTJ000//48.png");
MySprite res_ctj49(1, 1, "res//CTJ000//49.png");
MySprite res_ctj50(1, 1, "res//CTJ000//50.png");
MySprite res_ctj51(1, 1, "res//CTJ000//51.png");
MySprite res_ctj52(1, 1, "res//CTJ000//52.png");
MySprite res_ctj53(1, 1, "res//CTJ000//53.png");



MySprite* Res_ctj[54] = {	&res_ctj0 ,&res_ctj1 , &res_ctj2 , &res_ctj3 , &res_ctj4 ,&res_ctj5 ,&res_ctj6 ,&res_ctj7 ,&res_ctj8 ,&res_ctj9 ,
							& res_ctj10 ,& res_ctj11 ,& res_ctj12 ,& res_ctj13 ,& res_ctj14 ,& res_ctj15 ,& res_ctj16 ,& res_ctj17 ,& res_ctj18 ,& res_ctj19 , 
							& res_ctj20 ,& res_ctj21 ,& res_ctj22 ,& res_ctj23 ,& res_ctj24 ,& res_ctj25 ,& res_ctj26 ,& res_ctj27 ,& res_ctj28 ,& res_ctj29 , 
							& res_ctj30 ,& res_ctj31 ,& res_ctj32 ,& res_ctj33 ,& res_ctj34 ,& res_ctj35 ,& res_ctj36 ,& res_ctj37 ,& res_ctj38 ,& res_ctj39 ,
							& res_ctj40 ,& res_ctj41 ,& res_ctj42 ,& res_ctj43 ,& res_ctj44 ,& res_ctj45 ,& res_ctj46 ,& res_ctj47 ,& res_ctj48 ,& res_ctj49 ,
							& res_ctj50 ,& res_ctj51 ,& res_ctj52 ,& res_ctj53 
						};
#endif

#endif

//res\yuan
#if 1
MySprite res_yuan00(true, 64, 64,  "res\\yuan\\00.jpg");
MySprite res_yuan01(true, 64, 64,   "res\\yuan\\01.jpg");
MySprite res_yuan02(true, 64, 64,   "res\\yuan\\02.jpg");
MySprite res_yuan03(true, 64, 64,   "res\\yuan\\03.jpg");
MySprite res_yuan04(true, 64, 64,   "res\\yuan\\04.png");
MySprite res_yuan05(true, 64, 64,   "res\\yuan\\05.png");
MySprite res_yuan06(true, 64, 64,   "res\\yuan\\06.png");
MySprite res_yuan07(true, 64 * 4, 64 * 4,   "res\\yuan\\07.png");

MySprite res_yuan08(8, 1, "res\\yuan\\08.png");
MySprite res_yuan09(8, 1, "res\\yuan\\09.png");
MySprite res_yuan10(8, 1, "res\\yuan\\10.png");
MySprite res_yuan11(6, 1, "res\\yuan\\11.png");
MySprite res_yuan12(4, 1, "res\\yuan\\12.png");
MySprite res_yuan13(6, 1, "res\\yuan\\13.png");
MySprite res_yuan14(6, 1, "res\\yuan\\14.png");
MySprite res_yuan15(4, 1, "res\\yuan\\15.png");
MySprite res_yuan16(8, 1, "res\\yuan\\16.jpg");
MySprite res_yuan17(6, 1, "res\\yuan\\17.png");//

MySprite res_yuan18(6, 1, "res\\yuan\\18.png");
MySprite res_yuan19(4, 1, "res\\yuan\\19.png");//
MySprite res_yuan20(6, 1, "res\\yuan\\20.png");
MySprite res_yuan21(4, 1, "res\\yuan\\21.png");
MySprite res_yuan22(8, 1, "res\\yuan\\22.jpg");
MySprite res_yuan23(3, 1, "res\\yuan\\23.png");
MySprite res_yuan24(4, 1, "res\\yuan\\24.png");
MySprite res_yuan25(12, 1, "res\\yuan\\25.png");
MySprite res_yuan26(12, 1, "res\\yuan\\26.png");
MySprite res_yuan27(8, 1, "res\\yuan\\27.png");
MySprite res_yuan28(3, 1, "res\\yuan\\28.jpg");//
MySprite res_yuan29(4, 1, "res\\yuan\\29.png");
MySprite res_yuan30(4, 1, "res\\yuan\\30.png");

MySprite res_yuan31(6, 1, "res\\yuan\\31.png");
MySprite res_yuan32(4, 1, "res\\yuan\\32.png");
MySprite res_yuan33(6, 1, "res\\yuan\\33.png");
MySprite res_yuan34(4, 1, "res\\yuan\\34.png");
MySprite res_yuan35(6, 1, "res\\yuan\\35.png");
MySprite res_yuan36(6, 1, "res\\yuan\\36.png");
MySprite res_yuan37(6, 1, "res\\yuan\\37.png");
MySprite res_yuan38(6, 1, "res\\yuan\\38.png");
MySprite res_yuan39(6, 1, "res\\yuan\\39.png");
MySprite res_yuan40(6, 1, "res\\yuan\\40.png");
MySprite res_yuan41(6, 1, "res\\yuan\\41.png");

MySprite* Res_yuan[42] = { &res_yuan00 ,&res_yuan01 ,&res_yuan02 ,&res_yuan03 ,&res_yuan04 ,&res_yuan05 ,
						&res_yuan06 ,&res_yuan07 ,&res_yuan08 ,&res_yuan09 ,&res_yuan10 ,&res_yuan11,
						&res_yuan12,&res_yuan13,&res_yuan14,&res_yuan15,&res_yuan16,&res_yuan17,
						&res_yuan18,&res_yuan19,&res_yuan20,&res_yuan21,&res_yuan22,&res_yuan23,
						&res_yuan24,&res_yuan25,&res_yuan26,&res_yuan27,&res_yuan28,&res_yuan29,
						&res_yuan30,&res_yuan31,&res_yuan32,&res_yuan33,&res_yuan34,&res_yuan35,
						&res_yuan36,&res_yuan37,&res_yuan38,&res_yuan39,& res_yuan40,& res_yuan41 };
#endif

#endif