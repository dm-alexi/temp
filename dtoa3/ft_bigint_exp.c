/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_exp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 14:34:18 by sscarecr          #+#    #+#             */
/*   Updated: 2019/10/12 18:14:20 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bigint.h"

static const uint32_t	g_power2[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512,
	1024, 2048, 4096, 8192, 16384, 32768};
static const t_bigint	g_power2_big[] =
{
	{ 1, { 65536 } },
	{ 2, { 294967296, 4 } },
	{ 3, { 709551616, 446744073, 18 } },
	{ 5, { 768211456, 374607431, 938463463, 282366920, 340 } },
	{ 9, { 129639936, 584007913, 564039457, 984665640, 907853269, 985008687,
			195423570, 89237316, 115792 } },
	{18, { 6084096, 946433649, 811946569, 853753882, 186486050, 690031858,
			166903427, 801874298, 73546976, 721764030, 723561443, 592393377,
			479365820, 205846127, 574024998, 942597099, 407807929, 13 } },
	{35, { 224137216, 356329624, 716304835, 245938479, 298239947, 510684586,
			237163350, 110540827, 881473913, 682342462, 768838150, 952085005,
			119453082, 601246094, 276302219, 424865485, 377767893, 639474124,
			492847430, 814416622, 658789768, 871393357, 120113879, 407536021,
			708477322, 500963132, 732675805, 430081157, 230657273, 797697894,
			902473361, 930519078, 231590772, 769313486, 179 } },
	{69, { 596230656, 853611059, 148193555, 478604952, 604645318, 135433229,
			335543602, 166389437, 638215525, 268352998, 935045997, 580656697,
			469678542, 726931323, 725157101, 710820209, 227125684, 233287231,
			403697613, 301645904, 598351152, 461857357, 943603718, 177116725,
			258592864, 460314150, 26192708, 805659331, 322058077, 176035326,
			569494856, 974786564, 342420684, 333389668, 385521914, 399123930,
			808607552, 891541065, 42887575, 852036305, 470581645, 338476170,
			161838094, 642619756, 276792218, 384067568, 796057638, 389652106,
			750197750, 300996091, 630877367, 448283120, 88152386, 490921095,
			119559150, 898019494, 717960921, 913463688, 201411522, 890893197,
			655138867, 345427524, 484032130, 102669715, 951960444, 876688669,
			7300714, 6071311, 32317 } },
	{138, { 154190336, 708340403, 90243804, 738033436, 602920781, 491511131,
			726673216, 413467189, 903001302, 103126085, 338977648, 522981857,
			411929804, 148385078, 616910874, 2440926, 520317457, 884912819,
			746373296, 221846571, 550807568, 119433165, 329070473, 659250178,
			449867455, 624817718, 469201774, 996090799, 59899795, 850267253,
			763473223, 901781465, 447899971, 856440730, 926708342, 902916136,
			380631045, 154816321, 571642377, 919823050, 412945674, 440616007,
			782878948, 963395687, 693002122, 394905987, 223269061, 534517065,
			782954323, 791554849, 272884279, 134090584, 271106831, 611551794,
			790513399, 135459982, 14907159, 375124784, 419370285, 79921636,
			675195485, 17678006, 202313169, 270197698, 622102834, 380087608,
			825731835, 913245610, 23806505, 492194617, 862595674, 412344784,
			225998300, 368125550, 318492846, 656751221, 188091833, 796825837,
			933015213, 616369411, 550769983, 972088269, 850551032, 93668333,
			417061675, 41349008, 475100189, 872639496, 734087811, 914434496,
			486318237, 559885291, 541693835, 867714215, 15972399, 443059025,
			303026696, 432823469, 599579453, 190260940, 946905630, 881787785,
			686938976, 598029006, 467977783, 118609114, 284048740, 803704071,
			807908705, 586617496, 334684344, 712745672, 318839397, 946226376,
			70011855, 718314428, 590134383, 998340361, 976543709, 277945956,
			87851365, 607263236, 438185793, 837987573, 714439262, 340890106,
			934997558, 848826811, 971557456, 283953907, 384233483, 47383780,
			579964249, 716624382, 691752710, 413152506, 44388881, 1 } },
	{275, {	715792896, 505665475, 661997186, 468950587, 90806576, 581781469,
			266605403, 123214227, 433851147, 595650875, 254270163, 437610652,
			976000815, 660418822, 15189689, 244232028, 318547238, 397828465,
			31930023, 340362970, 675567650, 212638793, 867541113, 558524822,
			180441339, 896089189, 386855096, 198615747, 422101460, 118723781,
			873059614, 232758350, 333528009, 663962671, 321424808, 4288017,
			288906309, 813623833, 497355827, 963754561, 598185705, 964938414,
			360767529, 930596963, 973086090, 655703943, 538903974, 116099852,
			844095492, 385438585, 221977090, 707717942, 38077270, 576605881,
			19768025, 610474377, 367854754, 184617404, 949525227, 455928723,
			404904273, 265238595, 298834367, 437491311, 944530051, 641568336,
			185078350, 665169436, 308893304, 731966330, 676978589, 532776208,
			773821539, 18906023, 756509351, 536451620, 622796294, 76546186,
			951197087, 102958954, 234026821, 346236704, 944657061, 85693838,
			862594203, 152031231, 708699450, 528362987, 477466841, 873107937,
			276155607, 402992120, 216157115, 918035565, 179158765, 648693232,
			308430079, 61288818, 790754955, 2994422, 581819563, 340761738,
			93143648, 79393179, 815778153, 188769662, 629866808, 619387449,
			507571039, 422355148, 869806258, 363945290, 703622776, 372095228,
			372804574, 729303537, 281078209, 417183012, 24751419, 438785324,
			413033485, 856174822, 653616298, 498727603, 726219481, 714037868,
			941821189, 308356405, 211605960, 861598652, 493840581, 853813510,
			748727761, 930004777, 204118558, 738560008, 479877527, 115972927,
			845172954, 561090795, 54935621, 907352780, 578912967, 80978550,
			828936077, 357439653, 495834508, 4130725, 255670312, 213535470,
			315070087, 433955666, 915694234, 545336789, 878537675, 993638020,
			368621157, 658628383, 527611362, 763756314, 60556483, 599117426,
			242741410, 991961414, 827459339, 580434690, 72715611, 977764941,
			438018526, 790272448, 763427383, 982459184, 920967322, 364568754,
			632411049, 520878304, 276759160, 927564910, 27022310, 575137281,
			408157066, 82706715, 6263612, 620969857, 616749458, 117021823,
			359970390, 511868756, 495370993, 428167407, 434832877, 404885739,
			395310665, 181187406, 921691446, 435996308, 5427623, 409516168,
			635251626, 324396138, 221664970, 730828430, 786321505, 629547032,
			105748966, 492515342, 561271491, 655050115, 961120515, 49996900,
			683851737, 497257879, 945699168, 792761700, 45206501, 27627883,
			277368075, 743722432, 899226365, 757519164, 245131517, 382442812,
			47242407, 493565836, 578013326, 256438504, 616105920, 140814900,
			406677825, 694349945, 55617515, 279344088, 752768696, 843928918,
			293551245, 847426035, 364560014, 911005312, 195475653, 350501630,
			805880952, 800905297, 26535836, 10079600, 799917200, 900252535,
			886301017, 290553901, 324560121, 886542609, 638196771, 851613591,
			205159696, 825228048, 989538609, 298842192, 799078906, 765077554,
			63610979, 820177184, 273109870, 796157025, 223957291, 525201987,
			216264234, 849119295, 189721331, 431832786, 996232692, 448264161,
			733782862, 462984244, 619415929, 90748135, 1 } }
};
static const uint32_t	g_power5[] = {1, 5, 25, 125, 625, 3125, 15625, 78125};
static const t_bigint	g_power5_big[] =
{
	{ 1, { 390625 } },
	{ 2, { 587890625, 152 } },
	{ 3, { 962890625, 64365386, 23283 } },
	{ 5, { 712890625, 434970855, 3726400, 242752217, 542101086 } },
	{10, { 212890625, 863681793, 569604314, 377187926, 193021880, 454666389,
			305561419, 992184134, 705571876, 293873587 } },
	{20, {	212890625, 471103668, 747746862, 37770580, 466936530, 989468319,
			635969950, 939461496, 265605472, 34722882, 579715075, 31624270,
			701685918, 850237034, 644362813, 711160003, 628003995, 253863518,
			550944446, 86361685 } },
	{40, {	212890625, 685947418, 789578832, 153319891, 326499008, 846968657,
			927433551, 646003612, 336516628, 337206058, 265350215, 297563699,
			3222742, 31686823, 588507120, 414217260, 63914765, 446554365,
			435262941, 204074266, 781377495, 260792318, 84691481, 164829592,
			302660486, 728095225, 101453412, 603255836, 803361511, 890400427,
			304936174, 385070118, 333206278, 894271518, 534600406, 837376471,
			315462933, 743290965, 731200206, 7458340} },
	{80, {	212890625, 115634918, 615430273, 882267024, 559966957, 411689217,
			227385153, 373527284, 321466491, 319349449, 971173152, 579376695,
			352174724, 684328083, 472418242, 579033069, 918822547, 857127117,
			153763503, 540464179, 604036185, 331102750, 570042246, 347786926,
			170285190, 941051121, 803070715, 141608771, 140794537, 294051183,
			662825734, 841586939, 586657834, 816037776, 222290074, 490239782,
			753719892, 802858809, 299810833, 527144151, 124802899, 838448395,
			770466127, 996414561, 126272884, 289511290, 843748736, 994522193,
			957621869, 897719252, 991212515, 499214790, 718012279, 416453973,
			270166265, 355209381, 173562593, 798039126, 64590901, 990253686,
			300058261, 269449838, 442970528, 400309634, 836502721, 810854038,
			895275128, 683493275, 775514101, 78975312, 954896357, 110870347,
			185422180, 295763833, 399511558, 101605480, 817933310, 34577255,
			846462680, 55626 } },
	{160, {	212890625, 975009918, 235883153, 894055333, 301682057, 436245008,
			837875447, 393818295, 886413995, 132970518, 741074082, 144326123,
			23453904, 909024149, 614939687, 891431511, 794021082, 515223884,
			664437797, 905793492, 236389627, 737211017, 82751697, 842941691,
			618867296, 244483273, 512496833, 928512027, 380830535, 967905694,
			464468991, 700727869, 872795604, 509345843, 989004317, 226821613,
			214943424, 706149525, 526301841, 98041407, 231123914, 493790407,
			691037346, 882814425, 106725039, 626646859, 943292242, 199032074,
			904738561, 768942044, 106089243, 83773989, 747608740, 19200450,
			870513971, 914768937, 738912839, 862923975, 125460488, 812318348,
			990550253, 899920794, 80727232, 984057608, 229181777, 45778223,
			200031595, 158496357, 972236985, 477312372, 215461090, 65511912,
			226810193, 739157810, 232439143, 276973637, 454286462, 630162585,
			332530865, 629855975, 574196734, 303962042, 185143950, 279622020,
			755529109, 316525162, 894869108, 153293693, 601480084, 957489568,
			614881830, 397779068, 948881773, 846311568, 431198704, 761908315,
			55597131, 463378706, 845011043, 131556110, 679292686, 774878756,
			132363099, 352506681, 145304825, 524059270, 366960267, 176895018,
			728307404, 158045534, 471713015, 201600352, 864622912, 5616012,
			245495047, 528219980, 194205105, 763228422, 492580515, 776963848,
			42630551, 672005101, 819180980, 42613947, 201205757, 326289816,
			47583971, 430383849, 716320786, 634752768, 758201719, 451498396,
			914079919, 268273614, 869107175, 415532065, 280845687, 54554299,
			985187297, 736990470, 74284643, 125186061, 368138733, 300172368,
			587974858, 752196686, 925401811, 253241437, 556259795, 426352946,
			691229981, 217021364, 954098458, 884969045, 892556303, 971197853,
			480183369, 382578275, 94346047, 3 } },
	{319, {	212890625, 693759918, 351788915, 633208122, 873486872, 864309609,
			402875892, 612052295, 214189518, 503340972, 901833547, 130779495,
			946721504, 540859958, 791835097, 640634821, 141099186, 19826211,
			591170140, 540615985, 716407125, 294773597, 795531660, 948445618,
			837128678, 423313078, 884713475, 307646900, 868759816, 322297758,
			920240020, 122242991, 777670686, 537120441, 512027782, 224285613,
			877758480, 756559434, 642577916, 297647550, 973327408, 420418351,
			606944519, 797477261, 508784823, 642360053, 723086, 79492227,
			732403984, 147043497, 556864711, 840266702, 370832534, 826272501,
			102571600, 969773358, 86020250, 287881545, 580623983, 931269230,
			455697468, 725224655, 353137299, 684241353, 341693015, 832785913,
			113661281, 114675940, 604537206, 330207844, 974658022, 68423090,
			370855160, 63412570, 994489966, 898788898, 309775791, 345628359,
			12650038, 472081575, 308723604, 69954600, 156968341, 812890042,
			865047581, 647119098, 305746231, 285029060, 100285944, 832883059,
			917410365, 278654026, 554484350, 546865942, 656972885, 349183017,
			861280830, 609877301, 885236910, 817120138, 638162461, 209548858,
			278358009, 613801056, 993541129, 458167825, 868103235, 444736371,
			139390356, 701221066, 915213153, 455680466, 622690976, 202617435,
			986883677, 747336109, 619935293, 570590538, 94990704, 434499821,
			987600747, 236126476, 223136614, 81844425, 255805195, 41489738,
			114018844, 194054890, 388782693, 773988540, 391288765, 804563325,
			63430632, 64528038, 576110717, 426666561, 19193266, 176832183,
			585123157, 791224725, 889740856, 410867234, 677048562, 167496845,
			689440192, 9485969, 171592533, 43157475, 205110935, 76438130,
			301181899, 748258317, 755946439, 819510109, 639188971, 859026830,
			137376856, 767911127, 982001813, 977149345, 48800493, 62981925,
			615186278, 156428794, 282562208, 563970844, 7813370, 404222355,
			424997056, 57712222, 153316695, 187054725, 644954039, 912268932,
			653495493, 903583480, 172422039, 433377776, 869696243, 73069810,
			851329573, 924296468, 867830125, 89516611, 674919968, 23660202,
			810161700, 835514559, 629544654, 941497397, 954875187, 33512242,
			942142277, 122518666, 254880933, 443802240, 493517211, 702539721,
			134943833, 404073953, 570589685, 543609057, 330441211, 381822130,
			589157603, 925212412, 271878091, 210701452, 684765086, 636959242,
			481026697, 559593294, 298227630, 505438490, 253675872, 16846353,
			106047254, 474790584, 238747600, 852542243, 135485420, 1641021,
			757251430, 542957213, 296231407, 843770886, 60458924, 714241540,
			567114620, 498122610, 508686937, 132450399, 676029249, 828325707,
			309717470, 122037921, 533379434, 856384754, 506067208, 672946791,
			67316030, 31487764, 720082475, 928409759, 121252421, 655502955,
			979571804, 124243670, 567466556, 967653563, 745620688, 236114513,
			692198098, 451334411, 755586759, 314367307, 590320451, 510067121,
			359839412, 404104439, 111943019, 893540482, 389750767, 326293914,
			232858280, 362063835, 528569230, 200156301, 228527160, 604209688,
			316911954, 424916274, 387354475, 338897893, 642047110, 802646988,
			201093200, 755464670, 28791680, 838370589, 864094434, 861629351,
			269408552, 199422638, 678678567, 450514049, 432414593, 607670397,
			416079807, 511677548, 45496823, 705950168, 323105080, 775313284,
			347072341, 368507375, 298024886, 122840477, 219236321, 586996578,
			519012665, 520008249, 711592962, 887571963, 975580207, 504255225,
			545124789, 513494117, 330135503, 263322338, 773150482, 130846498,
			351498149, 59741741, 280420242, 946731012, 952185357, 574977460 } },
	{637, {	212890625, 131259918, 83600439, 973818388, 284657460, 882018105,
			551042152, 982881953, 318574187, 321411815, 290359340, 966859201,
			857437691, 86417027, 917919152, 575571655, 663577829, 157631832,
			937184862, 58950506, 976020026, 32587933, 229635306, 382928486,
			477289597, 302419023, 75840227, 14157098, 643729002, 770174955,
			711180980, 846074413, 403164954, 516601353, 333126001, 133347077,
			935293062, 444016471, 560739919, 742736685, 862942367, 195037106,
			38314325, 890884950, 229024588, 271331782, 644417803, 426806325,
			758892388, 669101825, 222084673, 468689836, 452947783, 938953275,
			451556033, 158409065, 992800741, 448264875, 697980413, 581798409,
			175114486, 47892846, 123679685, 191685053, 419880778, 209255515,
			306024557, 616293379, 224577640, 151715818, 442282567, 108693372,
			833171933, 627177407, 907810756, 294507210, 716720925, 283716582,
			324017101, 780651881, 815270857, 219136455, 695124372, 521341371,
			990646114, 964762643, 707843736, 165720549, 388391456, 899125452,
			381389511, 930884711, 886178462, 599076692, 645419043, 336154607,
			986805084, 989863762, 683634095, 366667360, 650967482, 67368811,
			750725281, 899270821, 156914872, 737160276, 733442162, 500388458,
			441034101, 422141637, 66116183, 538155898, 352056499, 508922257,
			54779534, 409553678, 666124066, 743703932, 227354928, 640395184,
			232671793, 713297726, 774746415, 647789460, 60758580, 492845248,
			140946038, 514128711, 9585465, 463385900, 840651596, 15642095,
			16580128, 913529610, 808773535, 357924871, 445454159, 476621654,
			10756566, 109703261, 328930234, 192189620, 368038517, 336461815,
			905846363, 110255127, 856561914, 659572939, 312536960, 905684795,
			333501644, 513462513, 609518194, 456652261, 770734328, 646494801,
			870325614, 881138370, 863304891, 47837746, 249683774, 842192448,
			897539764, 860996394, 831033416, 575394703, 889538007, 62922943,
			879280464, 161052952, 559945851, 742957003, 75866971, 226095091,
			605843700, 630227608, 226360177, 773095272, 454067011, 712005376,
			661600965, 893986281, 505040432, 504045842, 188147088, 728970264,
			862421682, 491459643, 294766368, 815896541, 342769717, 759051725,
			651956336, 411630799, 933554207, 41574797, 621668858, 899116754,
			380512439, 1992754, 665229081, 317203145, 914073929, 114985209,
			644786449, 131597676, 267893489, 268855610, 784383392, 192700608,
			371268928, 366141603, 81862358, 31543285, 92130742, 304428968,
			418676713, 260133509, 589094653, 936784465, 569341235, 10542173,
			983243981, 749793321, 247682522, 747658288, 307859017, 618857657,
			706336024, 331691177, 910755076, 31906179, 71061816, 464999945,
			134999278, 868500442, 578571798, 572302942, 141214891, 864901786,
			797450382, 962240840, 43884894, 19632409, 70287021, 258332192,
			687327215, 698080498, 726284034, 647811883, 902404831, 284897844,
			409036458, 60872476, 747325288, 671375455, 836337558, 721487622,
			387570775, 19388085, 255519751, 705854666, 61384482, 763196769,
			361088901, 295932214, 86047907, 125912169, 953877366, 623025187,
			699031149, 50906131, 578942706, 791643037, 341388735, 924670608,
			374095405, 232575307, 999327532, 908730445, 922981326, 570693629,
			486162569, 207108336, 532394632, 610664923, 100812380, 663201991,
			427053408, 252261074, 307202026, 662661840, 877590192, 376502354,
			501576593, 891985377, 115948646, 822424903, 699186564, 616268945,
			863422745, 355783149, 233947832, 686751077, 716169662, 29121085,
			375207743, 360748349, 977283514, 737153673, 289286863, 524848137,
			616488295, 549662683, 83839820, 969576560, 851103625, 358759800,
			652201794, 70967761, 690402340, 494037959, 96835431, 191872604,
			608366025, 168350043, 139526784, 555150496, 106323746, 422154614,
			64271531, 934704750, 365787149, 645706097, 480226632, 639943578,
			721554561, 141133222, 907311083, 793129174, 847808354, 2908676,
			47286086, 101007389, 366684810, 603673149, 53615246, 384231427,
			441939944, 825288459, 46717331, 714991135, 98219717, 567238057,
			318577516, 87006253, 536689917, 613903557, 715180314, 185038199,
			83451056, 678857287, 350265384, 27006746, 306444172, 262373882,
			360794777, 835888177, 835109597, 344412363, 856081753, 284079082,
			788652069, 613586417, 175812747, 18633854, 411253177, 688185240,
			833168902, 660621501, 941901933, 788288230, 544535568, 779546816,
			373393353, 102156763, 716311183, 710996596, 380657258, 838456098,
			337028324, 747611865, 359878434, 187034917, 224822564, 421808431,
			204512718, 911235546, 824658158, 632219126, 745348802, 592978755,
			418035892, 168812315, 459265816, 818411816, 837322566, 873857859,
			851391990, 416142868, 135311476, 710247829, 338184546, 221681391,
			704616021, 233425758, 632986718, 662722154, 384409411, 175287164,
			381893609, 53808585, 113895920, 290300835, 391865949, 581229280,
			508054593, 291102397, 447716936, 717537718, 302804212, 851437528,
			561499734, 147170570, 823409157, 272506239, 776108683, 817219726,
			842288207, 676149273, 565667551, 80586678, 122192373, 945387271,
			775701409, 291597219, 258823310, 583009770, 815585584, 46626513,
			776300498, 235331943, 327529688, 633642330, 110705723, 986130347,
			234785447, 106202212, 972431533, 967354765, 404379386, 312484823,
			952557284, 470568754, 459876282, 632425839, 343757723, 858609231,
			57569110, 517117641, 147635908, 459513078, 37835481, 831766257,
			596320023, 875216777, 928683522, 187301886, 16853701, 495999785,
			318084445, 502801396, 559198527, 740636366, 863787907, 696986360,
			391327065, 384363784, 595091543, 647645334, 430888757, 652465814,
			808677577, 325862414, 360243174, 722092718, 24480161, 494273613,
			546795904, 898492644, 185121117, 492634968, 863336000, 800426396,
			632135443, 872776560, 230616283, 514621676, 354909168, 23744389,
			893784168, 69395545, 487478971, 944946788, 224523118, 183976560,
			409091685, 640971466, 50492348, 713751162, 409226667, 160398983,
			918494366, 894147650, 375549017, 526894294, 78007671, 591885953,
			486984044, 368890905, 25598688, 68721785, 649473743, 21808461,
			820843442, 186013538, 781019086, 178475624, 781034996, 433249590,
			231857035, 415526273, 129645008, 300550489, 675646517, 437728492,
			962630861, 741057313, 958209728, 529067131, 971781983, 907342863,
			133880243, 494941600, 216676145, 653620885, 68515911, 339649729,
			897107029, 691452650, 110583612, 537420662, 847972312, 51147829,
			341687106, 5368176, 712447647, 480864333, 302307596, 484905038,
			168412816, 701132525, 336719068, 813122069, 61980708, 318615286,
			644778727, 361798679, 50825248, 767415387, 653179814, 396816958,
			852110627, 331939520, 227632672, 322286900, 633885676, 488504646,
			292940453, 862338546, 474827857, 179611748, 878995298, 597589460,
			226268028, 872286302, 120072809, 433007941, 220190190, 990942695,
			489131405, 441693919, 533744159, 998751214, 875082269, 178789895,
			715689622, 726965532, 269370759, 16469324, 444608861, 132111903,
			435398923, 56689525, 586921284, 789408388, 257635617, 149784701,
			688032830, 229913685, 780776928, 481539919, 850558860, 390898709,
			716784905, 835608979, 532010929, 35599620, 829192000, 131947526,
			928361864, 818248567, 424158297, 70619602, 742358281, 680193377,
			91 } }
};

void					ft_bigint_pow2(t_bigint *res, int32_t exp)
{
	t_bigint	tmp;
	t_bigint	*cur;
	int			i;

	i = 0;
	tmp.len = 1;
	tmp.arr[0] = g_power2[exp % 16];
	exp >>= 4;
	cur = &tmp;
	while (exp)
	{
		if (exp & 1)
		{
			ft_bigint_mult((cur == &tmp ? res : &tmp), cur, g_power2_big + i);
			cur = (cur == &tmp ? res : &tmp);
		}
		++i;
		exp >>= 1;
	}
	if (cur != res)
		ft_bigint_copy(res, cur);
}

void					ft_bigint_pow5(t_bigint *res, int32_t exp)
{
	t_bigint	tmp;
	t_bigint	*cur;
	int			i;

	i = 0;
	tmp.len = 1;
	tmp.arr[0] = g_power5[exp % 8];
	exp >>= 3;
	cur = &tmp;
	while (exp)
	{
		if (exp & 1)
		{
			ft_bigint_mult((cur == &tmp ? res : &tmp), cur, g_power5_big + i);
			cur = (cur == &tmp ? res : &tmp);
		}
		++i;
		exp >>= 1;
	}
	if (cur != res)
		ft_bigint_copy(res, cur);
}
