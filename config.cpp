class CfgPatches
{
    class ld3k_jca_hk437_compat_ace3
    {
        requiredAddons[]=
        {
            "Weapons_F_JCA_HK437",
            "Weapons_F_JCA_HK437_Rifles_HK437",
            "Weapons_F_JCA_HK437_Accessories"
        };
        requiredversion=0.1;
        units[]={};
        weapons[]={};
    };
};
class CfgAmmo
{
    class BulletBase;
    /*class B_762x51_Ball: BulletBase // official BI tool All-in-one Config Arma3 2.19.152606 https://community.bistudio.com/wiki/Arma:_All-in-one_Config
    {
        hit=11.6;
        indirectHit=0;
        indirectHitRange=0;
        cartridge="FxCartridge_762";
        visibleFire=3;
        audibleFire=45;
        dangerRadiusBulletClose=8;
        dangerRadiusHit=12;
        suppressionRadiusBulletClose=6;
        suppressionRadiusHit=8;
        cost=1.2;
        airLock=1;
        typicalSpeed=800;
        caliber=1.6;
        model="\A3\Weapons_f\Data\bullettracer\tracer_white";
        tracerScale=0.6;
        tracerStartTime=0.0075;
        tracerEndTime=5;
        airFriction=-0.001;
        class CamShakeExplode
        {
            power=2.82843;
            duration=0.6;
            frequency=20;
            distance=8.48528;
        };
        class CamShakeHit
        {
            power=5;
            duration=0.2;
            frequency=20;
            distance=1;
        };
    };
    class B_762x39_Ball_F: BulletBase
    {
        airLock=1;
        hit=11;
        indirectHit=0;
        indirectHitRange=0;
        typicalSpeed=730;
        airFriction=-0.0016;
        caliber=1.2;
        model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";
        tracerScale=1;
        tracerStartTime=0.05;
        tracerEndTime=1;
        nvgOnly=0;
        dangerRadiusBulletClose=8;
        dangerRadiusHit=12;
        suppressionRadiusBulletClose=6;
        suppressionRadiusHit=8;
        cartridge="FxCartridge_762x39";
    };*/
    class JCA_B_300BLK_Ball: BulletBase // JCA default config, Hornady Law Enforcement .300 Blackout 190gr SUB-X TAP according to HK437 Handbook https://www.heckler-koch.com/Downloads/Produktinformationen/EN/HK437%20Handbook%20EN.pdf
    {
        ACE_caliber=7.85; // https://bobp.cip-bobp.org/uploads/tdcc/tab-i/300-aac-blackout-180801-en.pdf
        ACE_bulletLength=33.73; // 1.328" https://static.hornady.media/presscenter/docs/1410995739-300-Blackout-Subsonic-190gr-SUB-X-TAP1681486905.pdf
        ACE_bulletMass=12.312; // 190gr
        // ACE_muzzleVelocityVariationSD=0.3; // ACE3 default value https://github.com/acemod/ACE3/blob/master/addons/advanced_ballistics/script_component.hpp#L32, effective standart deviation in-game ~1, ~2m/s (as IRL, series of muzzle velocity measurements in-game with standart deviation formula), should be ~3, ~5m/s for manufactured ammunitions
        ACE_ammoTempMuzzleVelocityShifts[]={-1.87,-1.82,-1.66,-1.4,-1.04,-0.57,0,0.68,1.46,2.34,3.33}; // Same curve default ACE_ammoTempMuzzleVelocityShifts /10. Muzzle velocity shift 0m/s ICAO conditions (15°C, 1013.25hPa, 0%)
        ACE_ballisticCoefficients[]={0.437}; // https://static.hornady.media/presscenter/docs/1410995739-300-Blackout-Subsonic-190gr-SUB-X-TAP1681486905.pdf
        ACE_velocityBoundaries[]={};
        ACE_standardAtmosphere="ICAO"; // https://www.hornady.com
        ACE_dragModel=1;
        ACE_barrelLengths[]={228.6}; // 9", HK437 official site https://www.heckler-koch.com/en/Products/Military%20and%20Law%20Enforcement/Assault%20rifles/HK437?section=variants&s=true
        ACE_muzzleVelocities[]={290}; // 290m/s 9" ICAO conditions (15°C, 1013.25hPa, 0%), HK437 Handbook https://www.heckler-koch.com/Downloads/Produktinformationen/EN/HK437%20Handbook%20EN.pdf
        hit=7.6; // Subsonic Polymer tipped expanding, 518 Joules, B_762x51_Ball 11.6, B_762x39_Ball_F 11, JCA 12
        visibleFire=1; // B_127x54_Ball, B_762x51_Ball 3
        audibleFire=5; // B_127x54_Ball, B_762x51_Ball 45
        dangerRadiusBulletClose=4; // B_127x54_Ball, B_762x51_Ball 8
        suppressionRadiusBulletClose=2; // B_127x54_Ball, B_762x51_Ball 6
        typicalSpeed=290; // B_762x51_Ball 800, 518 Joules
        caliber=0.96; // Subsonic Polymer tipped expanding, B_762x51_Ball 1.6, B_762x39_Ball_F 1.2
        // .300 Blackout 190gr SUB-X TAP, bare gelatin total penetration 17" velocity 998fps, "meat.bisurf" (bulletPenetrability 350): caliber ~4
        tracerStartTime=0.18; // Visible 140m 775m (typically 900m) 9g 820m/s ICAO according to https://www.nammo.com, ToF 140m 0.18s (Strelok Pro), B_762x51_Ball 0.0075
        tracerEndTime=1.87; // Visible 140m 775m (typically 900m) 9g 820m/s ICAO according to https://www.nammo.com, ToF 900m 1.87s (Strelok Pro), B_762x51_Ball 5
        airFriction=-0.00044673; // ICAO conditions (15°C, 1013.25hPa, 0%), airFrictionAnalysis.txt in docs folder
        class CamShakeExplode
        {
            power=2.23607; // B_127x54_Ball, B_762x51_Ball 2.82843
            duration=0.4; // B_127x54_Ball, B_762x51_Ball 0.6
            frequency=20; // B_127x54_Ball ,B_762x51_Ball 20
            distance=6.7082; // B_127x54_Ball, B_762x51_Ball 8.48528
        };
    };
    class JCA_B_300BLK_Ball_Tracer_Red: JCA_B_300BLK_Ball
    {
        visibleFire=5; // B_762x51_Ball 3, B_762x51_Minigun_Tracer_Red 5, BulletBase 3, BulletCore 16
    };
    class JCA_B_300BLK_Ball_Tracer_Green: JCA_B_300BLK_Ball
    {
        visibleFire=5; // B_762x51_Ball 3, B_762x51_Minigun_Tracer_Red 5, BulletBase 3, BulletCore 16
    };
    class JCA_B_300BLK_Ball_Tracer_Yellow: JCA_B_300BLK_Ball
    {
        visibleFire=5; // B_762x51_Ball 3, B_762x51_Minigun_Tracer_Red 5, BulletBase 3, BulletCore 16
    };
    class JCA_B_300BLK_Ball_Tracer_IR: JCA_B_300BLK_Ball
    {
        tracerScale=0.5; // IR dim tracer, B_556x45_Ball 1, B_65x39_Caseless 1, B_762x39_Ball_F 1, B_762x51_Ball 0.6
        tracerStartTime=0.02; // Visible 13m 775m (typically 1250m) 9g 840m/s ICAO according to https://www.nammo.com, ToF 13m 0.02s (Strelok Pro), B_762x51_Ball 0.0075
        tracerEndTime=3.03; // Visible 13m 775m (typically 1250m) 9g 840m/s ICAO according to https://www.nammo.com, ToF 1250m 3.03s (Strelok Pro), B_762x51_Ball 5
    };
    class JCA_B_300BLK_Ball_110gr: JCA_B_300BLK_Ball // Hornady Law Enforcement .300 Blackout 110gr TAP Urban according to HK437 Handbook https://www.heckler-koch.com/Downloads/Produktinformationen/EN/HK437%20Handbook%20EN.pdf
    {
        ACE_bulletLength=29.97; // 1.180" https://static.hornady.media/presscenter/docs/1410998618-300-Blackout-110gr-TAP-Urban.pdf
        ACE_bulletMass=7.128; // 110gr
        ACE_transonicStabilityCoef=1; // AB range card issue w/o, ACE3 default value 0.5 https://github.com/acemod/ACE3/blob/24e57825f7e75822e936282b36a3929bae189338/addons/advanced_ballistics/functions/fnc_readAmmoDataFromConfig.sqf#L40
        ACE_ammoTempMuzzleVelocityShifts[]={-3.74,-3.64,-3.32,-2.8,-2.08,-1.14,0,1.36,2.92,4.68,6.66}; // Same curve default ACE_ammoTempMuzzleVelocityShifts /5. Muzzle velocity shift 0m/s ICAO conditions (15°C, 1013.25hPa, 0%)
        ACE_ballisticCoefficients[]={0.290}; // https://www.hornadyle.com/rifle-ammunition/110-gr-tap-urban-300-blackout#!/
        ACE_muzzleVelocities[]={630}; // 630m/s 9" ICAO conditions (15°C, 1013.25hPa, 0%), HK437 Handbook https://www.heckler-koch.com/Downloads/Produktinformationen/EN/HK437%20Handbook%20EN.pdf
        hit=9.5; // Polymer tipped frangible, 1415 Joules, B_762x51_Ball 11.6, B_762x39_Ball_F 11
        visibleFire=3;
        audibleFire=45;
        dangerRadiusBulletClose=8;
        dangerRadiusHit=12;
        suppressionRadiusBulletClose=6;
        typicalSpeed=630; // B_762x51_Ball 800, 1415 Joules
        caliber=1.28; // Polymer tipped frangible, B_762x51_Ball 1.6, B_762x39_Ball_F 1.2
        // .300 Blackout 110gr TAP Urban, bare gelatin total penetration 12.75" velocity 2175fps (2025 Hornady Law Enforcement Military Catalog), "meat.bisurf" (bulletPenetrability 350): caliber ~1.4
        airFriction=-0.00151328; // ICAO conditions (15°C, 1013.25hPa, 0%), airFrictionAnalysis.txt in docs folder
        class CamShakeExplode
        {
            power=2.82843;
            duration=0.6;
            frequency=20;
            distance=8.48528;
        };
    };
    class JCA_B_300BLK_Ball_110gr_Tracer_Red: JCA_B_300BLK_Ball_110gr
    {
        visibleFire=5; // B_762x51_Ball 3, B_762x51_Minigun_Tracer_Red 5, BulletBase 3, BulletCore 16
        model="\A3\Weapons_f\Data\bullettracer\tracer_red";
    };
    class JCA_B_300BLK_Ball_110gr_Tracer_Green: JCA_B_300BLK_Ball_110gr_Tracer_Red
    {
        model="\A3\Weapons_f\Data\bullettracer\tracer_green";
    };
    class JCA_B_300BLK_Ball_110gr_Tracer_Yellow: JCA_B_300BLK_Ball_110gr_Tracer_Red
    {
        model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";
    };
    class JCA_B_300BLK_Ball_110gr_Tracer_IR: JCA_B_300BLK_Ball_110gr
    {
        tracerScale=0.5; // IR dim tracer, B_556x45_Ball 1, B_65x39_Caseless 1, B_762x39_Ball_F 1, B_762x51_Ball 0.6
        tracerStartTime=0.02; // Visible 13m 775m (typically 1250m) 9g 840m/s ICAO according to https://www.nammo.com, ToF 13m 0.02s (Strelok Pro), B_762x51_Ball 0.0075
        tracerEndTime=3.03; // Visible 13m 775m (typically 1250m) 9g 840m/s ICAO according to https://www.nammo.com, ToF 1250m 3.03s (Strelok Pro), B_762x51_Ball 5
        nvgOnly=1;
    };
};
class CfgMagazines
{
    class CA_Magazine;
    class JCA_30Rnd_300BLK_EMAG: CA_Magazine // JCA default config
    {
        mass=9.9; // 16.9, HK Gen3 magazine 30 rounds (empty) 158g + 30x 20.3g (190gr cartridge weight), 30Rnd_556x45_Stanag 8 (13.6)
        initSpeed=290; // according to ACE_muzzleVelocities ICAO conditions (15°C, 1013.25 hPa, 0%) and HK437 Handbook https://www.heckler-koch.com/Downloads/Produktinformationen/EN/HK437%20Handbook%20EN.pdf
        displaynameshort="Subsonic";
    };
    class JCA_30Rnd_300BLK_Red_EMAG: JCA_30Rnd_300BLK_EMAG
    {
    };
    class JCA_30Rnd_300BLK_Tracer_Red_EMAG: JCA_30Rnd_300BLK_Red_EMAG
    {
        displaynameshort="Subsonic-T";
    };
    class JCA_30Rnd_300BLK_Tracer_IR_EMAG: JCA_30Rnd_300BLK_Tracer_Red_EMAG
    {
        displaynameshort="Subsonic-T IR";
    };
    class JCA_30Rnd_300BLK_sand_EMAG: JCA_30Rnd_300BLK_EMAG
    {
    };
    class JCA_30Rnd_300BLK_Red_sand_EMAG: JCA_30Rnd_300BLK_sand_EMAG
    {
    };
    class JCA_30Rnd_300BLK_Tracer_Red_sand_EMAG: JCA_30Rnd_300BLK_Red_sand_EMAG
    {
        displaynameshort="Subsonic-T";
    };
    class JCA_30Rnd_300BLK_Tracer_IR_sand_EMAG: JCA_30Rnd_300BLK_Tracer_Red_sand_EMAG
    {
        displaynameshort="Subsonic-T IR";
    };
    class JCA_30Rnd_300BLK_110gr_EMAG: JCA_30Rnd_300BLK_EMAG
    {
        author="Laid3acK";
        displayName=".300 BLK 30Rnd 110gr EMAG";
        ammo="JCA_B_300BLK_Ball_110gr";
        mass=7.4; // 12.6, HK Gen3 magazine 30 rounds (empty) 158g + 30x 13.8g (110gr cartridge weight), 30Rnd_556x45_Stanag 8 (13.6)
        initSpeed=630; // according to ACE_muzzleVelocities ICAO conditions (15°C, 1013.25 hPa, 0%) and HK437 Handbook https://www.heckler-koch.com/Downloads/Produktinformationen/EN/HK437%20Handbook%20EN.pdf
        displaynameshort="Frangible";
    };
    class JCA_30Rnd_300BLK_110gr_Red_EMAG: JCA_30Rnd_300BLK_110gr_EMAG
    {
        author="Laid3acK";
        displayName=".300 BLK 30Rnd 110gr Reload Tracer (Red) EMAG";
        ammo="JCA_B_300BLK_Ball_110gr_Tracer_Red";
        lastRoundsTracer=4;
    };
    class JCA_30Rnd_300BLK_110gr_Green_EMAG: JCA_30Rnd_300BLK_110gr_Red_EMAG
    {
        author="Laid3acK";
        displayName=".300 BLK 30Rnd 110gr Reload Tracer (Green) EMAG";
        ammo="JCA_B_300BLK_Ball_110gr_Tracer_Green";
    };
    class JCA_30Rnd_300BLK_110gr_Yellow_EMAG: JCA_30Rnd_300BLK_110gr_Red_EMAG
    {
        author="Laid3acK";
        displayName=".300 BLK 30Rnd 110gr Reload Tracer (Yellow) EMAG";
        ammo="JCA_B_300BLK_Ball_110gr_Tracer_Yellow";
    };
    class JCA_30Rnd_300BLK_110gr_IR_EMAG: JCA_30Rnd_300BLK_110gr_Red_EMAG
    {
        author="Laid3acK";
        displayName=".300 BLK 30Rnd 110gr Reload Tracer (IR) EMAG";
        ammo="JCA_B_300BLK_Ball_110gr_Tracer_IR";
    };
    class JCA_30Rnd_300BLK_110gr_Tracer_Red_EMAG: JCA_30Rnd_300BLK_110gr_Red_EMAG
    {
        author="Laid3acK";
        displayName=".300 BLK 30Rnd 110gr Tracer (Red) EMAG";
        tracersEvery=1;
        displaynameshort="Frangible-T";
    };
    class JCA_30Rnd_300BLK_110gr_Tracer_Green_EMAG: JCA_30Rnd_300BLK_110gr_Tracer_Red_EMAG
    {
        author="Laid3acK";
        displayName=".300 BLK 30Rnd 110gr Tracer (Green) EMAG";
        ammo="JCA_B_300BLK_Ball_110gr_Tracer_Green";
    };
    class JCA_30Rnd_300BLK_110gr_Tracer_Yellow_EMAG: JCA_30Rnd_300BLK_110gr_Tracer_Red_EMAG
    {
        author="Laid3acK";
        displayName=".300 BLK 30Rnd 110gr Tracer (Yellow) EMAG";
        ammo="JCA_B_300BLK_Ball_110gr_Tracer_Yellow";
    };
    class JCA_30Rnd_300BLK_110gr_Tracer_IR_EMAG: JCA_30Rnd_300BLK_110gr_Tracer_Red_EMAG
    {
        author="Laid3acK";
        displayName=".300 BLK 30Rnd 110gr Tracer (IR) EMAG";
        ammo="JCA_B_300BLK_Ball_110gr_Tracer_IR";
        displaynameshort="Frangible-T IR";
    };
    class JCA_30Rnd_300BLK_110gr_sand_EMAG: JCA_30Rnd_300BLK_sand_EMAG
    {
        author="Laid3acK";
        displayName=".300 BLK 30Rnd 110gr Sand EMAG";
        ammo="JCA_B_300BLK_Ball_110gr";
        mass=7.4; // 12.6, HK Gen3 magazine 30 rounds (empty) 158g + 30x 13.8g (110gr cartridge weight), 30Rnd_556x45_Stanag 8 (13.6)
        initSpeed=630; // according to ACE_muzzleVelocities ICAO conditions (15°C, 1013.25 hPa, 0%) and HK437 Handbook https://www.heckler-koch.com/Downloads/Produktinformationen/EN/HK437%20Handbook%20EN.pdf
        displaynameshort="Frangible";
    };
    class JCA_30Rnd_300BLK_110gr_Red_sand_EMAG: JCA_30Rnd_300BLK_110gr_sand_EMAG
    {
        author="Laid3acK";
        displayName=".300 BLK 30Rnd 110gr Reload Tracer (Red) Sand EMAG";
        ammo="JCA_B_300BLK_Ball_110gr_Tracer_Red";
        lastRoundsTracer=4;
    };
    class JCA_30Rnd_300BLK_110gr_Green_sand_EMAG: JCA_30Rnd_300BLK_110gr_Red_sand_EMAG
    {
        author="Laid3acK";
        displayName=".300 BLK 30Rnd 110gr Reload Tracer (Green) Sand EMAG";
        ammo="JCA_B_300BLK_Ball_110gr_Tracer_Green";
    };
    class JCA_30Rnd_300BLK_110gr_Yellow_sand_EMAG: JCA_30Rnd_300BLK_110gr_Red_sand_EMAG
    {
        author="Laid3acK";
        displayName=".300 BLK 30Rnd 110gr Reload Tracer (Yellow) Sand EMAG";
        ammo="JCA_B_300BLK_Ball_110gr_Tracer_Yellow";
    };
    class JCA_30Rnd_300BLK_110gr_IR_sand_EMAG: JCA_30Rnd_300BLK_110gr_Red_sand_EMAG
    {
        author="Laid3acK";
        displayName=".300 BLK 30Rnd 110gr Reload Tracer (IR) Sand EMAG";
        ammo="JCA_B_300BLK_Ball_110gr_Tracer_IR";
    };
    class JCA_30Rnd_300BLK_110gr_Tracer_Red_sand_EMAG: JCA_30Rnd_300BLK_110gr_Red_sand_EMAG
    {
        author="Laid3acK";
        displayName=".300 BLK 30Rnd 110gr Tracer (Red) Sand EMAG";
        tracersEvery=1;
        displaynameshort="Frangible-T";
    };
    class JCA_30Rnd_300BLK_110gr_Tracer_Green_sand_EMAG: JCA_30Rnd_300BLK_110gr_Tracer_Red_sand_EMAG
    {
        author="Laid3acK";
        displayName=".300 BLK 30Rnd 110gr Tracer (Green) Sand EMAG";
        ammo="JCA_B_300BLK_Ball_110gr_Tracer_Green";
    };
    class JCA_30Rnd_300BLK_110gr_Tracer_Yellow_sand_EMAG: JCA_30Rnd_300BLK_110gr_Tracer_Red_sand_EMAG
    {
        author="Laid3acK";
        displayName=".300 BLK 30Rnd 110gr Tracer (Yellow) Sand EMAG";
        ammo="JCA_B_300BLK_Ball_110gr_Tracer_Yellow";
    };
    class JCA_30Rnd_300BLK_110gr_Tracer_IR_sand_EMAG: JCA_30Rnd_300BLK_110gr_Tracer_Red_sand_EMAG
    {
        author="Laid3acK";
        displayName=".300 BLK 30Rnd 110gr Tracer (IR) Sand EMAG";
        ammo="JCA_B_300BLK_Ball_110gr_Tracer_IR";
        displaynameshort="Frangible-T IR";
    };
};
class CfgMagazineWells
{
    class JCA_HK437_300BLK // JCA default config
    {
        JCA_Magazines[]= // Weapon initSpeed -1 ACE_barrelLength 228.6mm (9"): 290, 630m/s ICAO conditions (15°C, 1013.25 hPa, 0%) according to JCA_30Rnd_300BLK magazines initSpeed
        {
            "JCA_30Rnd_300BLK_EMAG",
            "JCA_30Rnd_300BLK_Red_EMAG",
            "JCA_30Rnd_300BLK_Green_EMAG",
            "JCA_30Rnd_300BLK_Yellow_EMAG",
            "JCA_30Rnd_300BLK_IR_EMAG",
            "JCA_30Rnd_300BLK_Tracer_Red_EMAG",
            "JCA_30Rnd_300BLK_Tracer_Green_EMAG",
            "JCA_30Rnd_300BLK_Tracer_Yellow_EMAG",
            "JCA_30Rnd_300BLK_Tracer_IR_EMAG",
            "JCA_30Rnd_300BLK_110gr_EMAG",
            "JCA_30Rnd_300BLK_110gr_Red_EMAG",
            "JCA_30Rnd_300BLK_110gr_Green_EMAG",
            "JCA_30Rnd_300BLK_110gr_Yellow_EMAG",
            "JCA_30Rnd_300BLK_110gr_IR_EMAG",
            "JCA_30Rnd_300BLK_110gr_Tracer_Red_EMAG",
            "JCA_30Rnd_300BLK_110gr_Tracer_Green_EMAG",
            "JCA_30Rnd_300BLK_110gr_Tracer_Yellow_EMAG",
            "JCA_30Rnd_300BLK_110gr_Tracer_IR_EMAG",
            "JCA_30Rnd_300BLK_sand_EMAG",
            "JCA_30Rnd_300BLK_Red_sand_EMAG",
            "JCA_30Rnd_300BLK_Green_sand_EMAG",
            "JCA_30Rnd_300BLK_Yellow_sand_EMAG",
            "JCA_30Rnd_300BLK_IR_sand_EMAG",
            "JCA_30Rnd_300BLK_Tracer_Red_sand_EMAG",
            "JCA_30Rnd_300BLK_Tracer_Green_sand_EMAG",
            "JCA_30Rnd_300BLK_Tracer_Yellow_sand_EMAG",
            "JCA_30Rnd_300BLK_Tracer_IR_sand_EMAG",
            "JCA_30Rnd_300BLK_110gr_sand_EMAG",
            "JCA_30Rnd_300BLK_110gr_Red_sand_EMAG",
            "JCA_30Rnd_300BLK_110gr_Green_sand_EMAG",
            "JCA_30Rnd_300BLK_110gr_Yellow_sand_EMAG",
            "JCA_30Rnd_300BLK_110gr_IR_sand_EMAG",
            "JCA_30Rnd_300BLK_110gr_Tracer_Red_sand_EMAG",
            "JCA_30Rnd_300BLK_110gr_Tracer_Green_sand_EMAG",
            "JCA_30Rnd_300BLK_110gr_Tracer_Yellow_sand_EMAG",
            "JCA_30Rnd_300BLK_110gr_Tracer_IR_sand_EMAG"
        };
    };
};
class Mode_SemiAuto;
class Mode_FullAuto;
class CfgWeapons
{
    class ItemCore;
    class JCA_arifle_HK437_base_F;
    class JCA_arifle_HK437_AFG_base_F: JCA_arifle_HK437_base_F
    {
        class WeaponSlotsInfo;
        class Single;
        class FullAuto;
    };
    class JCA_arifle_HK437_VFG_base_F: JCA_arifle_HK437_base_F
    {
        class WeaponSlotsInfo;
        class Single;
        class FullAuto;
    };
    class JCA_arifle_HK437_AFG_black_F: JCA_arifle_HK437_AFG_base_F
    {
        ACE_barrelTwist=203.2; // 1:8" https://www.heckler-koch.com/Downloads/Produktinformationen/EN/HK437%20Handbook%20EN.pdf
        ACE_barrelLength=228.6; // 9"
        ACE_railHeightAboveBore=3.71386; // ACE3 checkScopes.sqf
        maxZeroing=700; // distance .300 Blackout 110gr TAP Urban Mach 0.8 (272m/s) ICAO
        initSpeed=-1; // 290, 630m/s according to ACE_muzzleVelocities ICAO conditions (15°C, 1013.25hPa, 0%) and HK437 Handbook https://www.heckler-koch.com/Downloads/Produktinformationen/EN/HK437%20Handbook%20EN.pdf
        magazines[]=
        {
            "JCA_30Rnd_300BLK_EMAG",
            "JCA_30Rnd_300BLK_Red_EMAG",
            "JCA_30Rnd_300BLK_Green_EMAG",
            "JCA_30Rnd_300BLK_Yellow_EMAG",
            "JCA_30Rnd_300BLK_IR_EMAG",
            "JCA_30Rnd_300BLK_Tracer_Red_EMAG",
            "JCA_30Rnd_300BLK_Tracer_Green_EMAG",
            "JCA_30Rnd_300BLK_Tracer_Yellow_EMAG",
            "JCA_30Rnd_300BLK_Tracer_IR_EMAG",
            "JCA_30Rnd_300BLK_110gr_EMAG",
            "JCA_30Rnd_300BLK_110gr_Red_EMAG",
            "JCA_30Rnd_300BLK_110gr_Green_EMAG",
            "JCA_30Rnd_300BLK_110gr_Yellow_EMAG",
            "JCA_30Rnd_300BLK_110gr_IR_EMAG",
            "JCA_30Rnd_300BLK_110gr_Tracer_Red_EMAG",
            "JCA_30Rnd_300BLK_110gr_Tracer_Green_EMAG",
            "JCA_30Rnd_300BLK_110gr_Tracer_Yellow_EMAG",
            "JCA_30Rnd_300BLK_110gr_Tracer_IR_EMAG",
            "JCA_30Rnd_300BLK_sand_EMAG",
            "JCA_30Rnd_300BLK_Red_sand_EMAG",
            "JCA_30Rnd_300BLK_Green_sand_EMAG",
            "JCA_30Rnd_300BLK_Yellow_sand_EMAG",
            "JCA_30Rnd_300BLK_IR_sand_EMAG",
            "JCA_30Rnd_300BLK_Tracer_Red_sand_EMAG",
            "JCA_30Rnd_300BLK_Tracer_Green_sand_EMAG",
            "JCA_30Rnd_300BLK_Tracer_Yellow_sand_EMAG",
            "JCA_30Rnd_300BLK_Tracer_IR_sand_EMAG",
            "JCA_30Rnd_300BLK_110gr_sand_EMAG",
            "JCA_30Rnd_300BLK_110gr_Red_sand_EMAG",
            "JCA_30Rnd_300BLK_110gr_Green_sand_EMAG",
            "JCA_30Rnd_300BLK_110gr_Yellow_sand_EMAG",
            "JCA_30Rnd_300BLK_110gr_IR_sand_EMAG",
            "JCA_30Rnd_300BLK_110gr_Tracer_Red_sand_EMAG",
            "JCA_30Rnd_300BLK_110gr_Tracer_Green_sand_EMAG",
            "JCA_30Rnd_300BLK_110gr_Tracer_Yellow_sand_EMAG",
            "JCA_30Rnd_300BLK_110gr_Tracer_IR_sand_EMAG"
        };
        class WeaponSlotsInfo: WeaponSlotsInfo
        {
            mass=68.3; // 3.1kg https://www.heckler-koch.com, JCA 70
        };
        class Single: Single
        {
            dispersion=0.0004; // 2.46 MOA (*0.562*0.000291), 0.562 value from https://github.com/acemod/ACE3/pull/5755, JCA 0.00065 (2.23 MOA)
        };
        class FullAuto: FullAuto
        {
            dispersion=0.0004; // 2.46 MOA (*0.562*0.000291), 0.562 value from https://github.com/acemod/ACE3/pull/5755, JCA 0.00065 (2.23 MOA)
        };
    };
    class JCA_arifle_HK437_VFG_black_F: JCA_arifle_HK437_VFG_base_F
    {
        ACE_barrelTwist=203.2; // 1:8" https://www.heckler-koch.com/Downloads/Produktinformationen/EN/HK437%20Handbook%20EN.pdf
        ACE_barrelLength=228.6; // 9"
        ACE_railHeightAboveBore=3.71386; // ACE3 checkScopes.sqf
        maxZeroing=700; // distance .300 Blackout 110gr TAP Urban Mach 0.8 (272m/s) ICAO
        initSpeed=-1; // 290, 630m/s according to ACE_muzzleVelocities ICAO conditions (15°C, 1013.25hPa, 0%) and HK437 Handbook https://www.heckler-koch.com/Downloads/Produktinformationen/EN/HK437%20Handbook%20EN.pdf
        magazines[]=
        {
            "JCA_30Rnd_300BLK_EMAG",
            "JCA_30Rnd_300BLK_Red_EMAG",
            "JCA_30Rnd_300BLK_Green_EMAG",
            "JCA_30Rnd_300BLK_Yellow_EMAG",
            "JCA_30Rnd_300BLK_IR_EMAG",
            "JCA_30Rnd_300BLK_Tracer_Red_EMAG",
            "JCA_30Rnd_300BLK_Tracer_Green_EMAG",
            "JCA_30Rnd_300BLK_Tracer_Yellow_EMAG",
            "JCA_30Rnd_300BLK_Tracer_IR_EMAG",
            "JCA_30Rnd_300BLK_110gr_EMAG",
            "JCA_30Rnd_300BLK_110gr_Red_EMAG",
            "JCA_30Rnd_300BLK_110gr_Green_EMAG",
            "JCA_30Rnd_300BLK_110gr_Yellow_EMAG",
            "JCA_30Rnd_300BLK_110gr_IR_EMAG",
            "JCA_30Rnd_300BLK_110gr_Tracer_Red_EMAG",
            "JCA_30Rnd_300BLK_110gr_Tracer_Green_EMAG",
            "JCA_30Rnd_300BLK_110gr_Tracer_Yellow_EMAG",
            "JCA_30Rnd_300BLK_110gr_Tracer_IR_EMAG",
            "JCA_30Rnd_300BLK_sand_EMAG",
            "JCA_30Rnd_300BLK_Red_sand_EMAG",
            "JCA_30Rnd_300BLK_Green_sand_EMAG",
            "JCA_30Rnd_300BLK_Yellow_sand_EMAG",
            "JCA_30Rnd_300BLK_IR_sand_EMAG",
            "JCA_30Rnd_300BLK_Tracer_Red_sand_EMAG",
            "JCA_30Rnd_300BLK_Tracer_Green_sand_EMAG",
            "JCA_30Rnd_300BLK_Tracer_Yellow_sand_EMAG",
            "JCA_30Rnd_300BLK_Tracer_IR_sand_EMAG",
            "JCA_30Rnd_300BLK_110gr_sand_EMAG",
            "JCA_30Rnd_300BLK_110gr_Red_sand_EMAG",
            "JCA_30Rnd_300BLK_110gr_Green_sand_EMAG",
            "JCA_30Rnd_300BLK_110gr_Yellow_sand_EMAG",
            "JCA_30Rnd_300BLK_110gr_IR_sand_EMAG",
            "JCA_30Rnd_300BLK_110gr_Tracer_Red_sand_EMAG",
            "JCA_30Rnd_300BLK_110gr_Tracer_Green_sand_EMAG",
            "JCA_30Rnd_300BLK_110gr_Tracer_Yellow_sand_EMAG",
            "JCA_30Rnd_300BLK_110gr_Tracer_IR_sand_EMAG"
        };
        class WeaponSlotsInfo: WeaponSlotsInfo
        {
            mass=68.3; // 3.1kg https://www.heckler-koch.com, JCA 70
        };
        class Single: Single
        {
            dispersion=0.0004; // 2.46 MOA (*0.562*0.000291), 0.562 value from https://github.com/acemod/ACE3/pull/5755, JCA 0.00065 (2.23 MOA)
        };
        class FullAuto: FullAuto
        {
            dispersion=0.0004; // 2.46 MOA (*0.562*0.000291), 0.562 value from https://github.com/acemod/ACE3/pull/5755, JCA 0.00065 (2.23 MOA)
        };
    };
    class JCA_arifle_HK437_AFG_sand_F: JCA_arifle_HK437_AFG_base_F
    {
        ACE_barrelTwist=203.2; // 1:8" https://www.heckler-koch.com/Downloads/Produktinformationen/EN/HK437%20Handbook%20EN.pdf
        ACE_barrelLength=228.6; // 9"
        ACE_railHeightAboveBore=3.71386; // ACE3 checkScopes.sqf
        maxZeroing=700; // distance .300 Blackout 110gr TAP Urban Mach 0.8 (272m/s) ICAO
        initSpeed=-1; // 290, 630m/s according to ACE_muzzleVelocities ICAO conditions (15°C, 1013.25hPa, 0%) and HK437 Handbook https://www.heckler-koch.com/Downloads/Produktinformationen/EN/HK437%20Handbook%20EN.pdf
        magazines[]=
        {
            "JCA_30Rnd_300BLK_sand_EMAG",
            "JCA_30Rnd_300BLK_Red_sand_EMAG",
            "JCA_30Rnd_300BLK_Green_sand_EMAG",
            "JCA_30Rnd_300BLK_Yellow_sand_EMAG",
            "JCA_30Rnd_300BLK_IR_sand_EMAG",
            "JCA_30Rnd_300BLK_Tracer_Red_sand_EMAG",
            "JCA_30Rnd_300BLK_Tracer_Green_sand_EMAG",
            "JCA_30Rnd_300BLK_Tracer_Yellow_sand_EMAG",
            "JCA_30Rnd_300BLK_Tracer_IR_sand_EMAG",
            "JCA_30Rnd_300BLK_110gr_sand_EMAG",
            "JCA_30Rnd_300BLK_110gr_Red_sand_EMAG",
            "JCA_30Rnd_300BLK_110gr_Green_sand_EMAG",
            "JCA_30Rnd_300BLK_110gr_Yellow_sand_EMAG",
            "JCA_30Rnd_300BLK_110gr_IR_sand_EMAG",
            "JCA_30Rnd_300BLK_110gr_Tracer_Red_sand_EMAG",
            "JCA_30Rnd_300BLK_110gr_Tracer_Green_sand_EMAG",
            "JCA_30Rnd_300BLK_110gr_Tracer_Yellow_sand_EMAG",
            "JCA_30Rnd_300BLK_110gr_Tracer_IR_sand_EMAG",
            "JCA_30Rnd_300BLK_EMAG",
            "JCA_30Rnd_300BLK_Red_EMAG",
            "JCA_30Rnd_300BLK_Green_EMAG",
            "JCA_30Rnd_300BLK_Yellow_EMAG",
            "JCA_30Rnd_300BLK_IR_EMAG",
            "JCA_30Rnd_300BLK_Tracer_Red_EMAG",
            "JCA_30Rnd_300BLK_Tracer_Green_EMAG",
            "JCA_30Rnd_300BLK_Tracer_Yellow_EMAG",
            "JCA_30Rnd_300BLK_Tracer_IR_EMAG",
            "JCA_30Rnd_300BLK_110gr_EMAG",
            "JCA_30Rnd_300BLK_110gr_Red_EMAG",
            "JCA_30Rnd_300BLK_110gr_Green_EMAG",
            "JCA_30Rnd_300BLK_110gr_Yellow_EMAG",
            "JCA_30Rnd_300BLK_110gr_IR_EMAG",
            "JCA_30Rnd_300BLK_110gr_Tracer_Red_EMAG",
            "JCA_30Rnd_300BLK_110gr_Tracer_Green_EMAG",
            "JCA_30Rnd_300BLK_110gr_Tracer_Yellow_EMAG",
            "JCA_30Rnd_300BLK_110gr_Tracer_IR_EMAG"
        };
        class WeaponSlotsInfo: WeaponSlotsInfo
        {
            mass=68.3; // 3.1kg https://www.heckler-koch.com, JCA 70
        };
        class Single: Single
        {
            dispersion=0.0004; // 2.46 MOA (*0.562*0.000291), 0.562 value from https://github.com/acemod/ACE3/pull/5755, JCA 0.00065 (2.23 MOA)
        };
        class FullAuto: FullAuto
        {
            dispersion=0.0004; // 2.46 MOA (*0.562*0.000291), 0.562 value from https://github.com/acemod/ACE3/pull/5755, JCA 0.00065 (2.23 MOA)
        };
    };
    class JCA_arifle_HK437_VFG_sand_F: JCA_arifle_HK437_VFG_base_F
    {
        ACE_barrelTwist=203.2; // 1:8" https://www.heckler-koch.com/Downloads/Produktinformationen/EN/HK437%20Handbook%20EN.pdf
        ACE_barrelLength=228.6; // 9"
        ACE_railHeightAboveBore=3.71386; // ACE3 checkScopes.sqf
        maxZeroing=700; // distance .300 Blackout 110gr TAP Urban Mach 0.8 (272m/s) ICAO
        initSpeed=-1; // 290, 630m/s according to ACE_muzzleVelocities ICAO conditions (15°C, 1013.25hPa, 0%) and HK437 Handbook https://www.heckler-koch.com/Downloads/Produktinformationen/EN/HK437%20Handbook%20EN.pdf
        magazines[]=
        {
            "JCA_30Rnd_300BLK_sand_EMAG",
            "JCA_30Rnd_300BLK_Red_sand_EMAG",
            "JCA_30Rnd_300BLK_Green_sand_EMAG",
            "JCA_30Rnd_300BLK_Yellow_sand_EMAG",
            "JCA_30Rnd_300BLK_IR_sand_EMAG",
            "JCA_30Rnd_300BLK_Tracer_Red_sand_EMAG",
            "JCA_30Rnd_300BLK_Tracer_Green_sand_EMAG",
            "JCA_30Rnd_300BLK_Tracer_Yellow_sand_EMAG",
            "JCA_30Rnd_300BLK_Tracer_IR_sand_EMAG",
            "JCA_30Rnd_300BLK_110gr_sand_EMAG",
            "JCA_30Rnd_300BLK_110gr_Red_sand_EMAG",
            "JCA_30Rnd_300BLK_110gr_Green_sand_EMAG",
            "JCA_30Rnd_300BLK_110gr_Yellow_sand_EMAG",
            "JCA_30Rnd_300BLK_110gr_IR_sand_EMAG",
            "JCA_30Rnd_300BLK_110gr_Tracer_Red_sand_EMAG",
            "JCA_30Rnd_300BLK_110gr_Tracer_Green_sand_EMAG",
            "JCA_30Rnd_300BLK_110gr_Tracer_Yellow_sand_EMAG",
            "JCA_30Rnd_300BLK_110gr_Tracer_IR_sand_EMAG",
            "JCA_30Rnd_300BLK_EMAG",
            "JCA_30Rnd_300BLK_Red_EMAG",
            "JCA_30Rnd_300BLK_Green_EMAG",
            "JCA_30Rnd_300BLK_Yellow_EMAG",
            "JCA_30Rnd_300BLK_IR_EMAG",
            "JCA_30Rnd_300BLK_Tracer_Red_EMAG",
            "JCA_30Rnd_300BLK_Tracer_Green_EMAG",
            "JCA_30Rnd_300BLK_Tracer_Yellow_EMAG",
            "JCA_30Rnd_300BLK_Tracer_IR_EMAG",
            "JCA_30Rnd_300BLK_110gr_EMAG",
            "JCA_30Rnd_300BLK_110gr_Red_EMAG",
            "JCA_30Rnd_300BLK_110gr_Green_EMAG",
            "JCA_30Rnd_300BLK_110gr_Yellow_EMAG",
            "JCA_30Rnd_300BLK_110gr_IR_EMAG",
            "JCA_30Rnd_300BLK_110gr_Tracer_Red_EMAG",
            "JCA_30Rnd_300BLK_110gr_Tracer_Green_EMAG",
            "JCA_30Rnd_300BLK_110gr_Tracer_Yellow_EMAG",
            "JCA_30Rnd_300BLK_110gr_Tracer_IR_EMAG"
        };
        class WeaponSlotsInfo: WeaponSlotsInfo
        {
            mass=68.3; // 3.1kg https://www.heckler-koch.com, JCA 70
        };
        class Single: Single
        {
            dispersion=0.0004; // 2.46 MOA (*0.562*0.000291), 0.562 value from https://github.com/acemod/ACE3/pull/5755, JCA 0.00065 (2.23 MOA)
        };
        class FullAuto: FullAuto
        {
            dispersion=0.0004; // 2.46 MOA (*0.562*0.000291), 0.562 value from https://github.com/acemod/ACE3/pull/5755, JCA 0.00065 (2.23 MOA)
        };
    };
    class JCA_arifle_HK437_AFG_olive_F: JCA_arifle_HK437_AFG_base_F
    {
        ACE_barrelTwist=203.2; // 1:8" https://www.heckler-koch.com/Downloads/Produktinformationen/EN/HK437%20Handbook%20EN.pdf
        ACE_barrelLength=228.6; // 9"
        ACE_railHeightAboveBore=3.71386; // ACE3 checkScopes.sqf
        maxZeroing=700; // distance .300 Blackout 110gr TAP Urban Mach 0.8 (272m/s) ICAO
        initSpeed=-1; // 290, 630m/s according to ACE_muzzleVelocities ICAO conditions (15°C, 1013.25hPa, 0%) and HK437 Handbook https://www.heckler-koch.com/Downloads/Produktinformationen/EN/HK437%20Handbook%20EN.pdf
        magazines[]=
        {
            "JCA_30Rnd_300BLK_EMAG",
            "JCA_30Rnd_300BLK_Red_EMAG",
            "JCA_30Rnd_300BLK_Green_EMAG",
            "JCA_30Rnd_300BLK_Yellow_EMAG",
            "JCA_30Rnd_300BLK_IR_EMAG",
            "JCA_30Rnd_300BLK_Tracer_Red_EMAG",
            "JCA_30Rnd_300BLK_Tracer_Green_EMAG",
            "JCA_30Rnd_300BLK_Tracer_Yellow_EMAG",
            "JCA_30Rnd_300BLK_Tracer_IR_EMAG",
            "JCA_30Rnd_300BLK_110gr_EMAG",
            "JCA_30Rnd_300BLK_110gr_Red_EMAG",
            "JCA_30Rnd_300BLK_110gr_Green_EMAG",
            "JCA_30Rnd_300BLK_110gr_Yellow_EMAG",
            "JCA_30Rnd_300BLK_110gr_IR_EMAG",
            "JCA_30Rnd_300BLK_110gr_Tracer_Red_EMAG",
            "JCA_30Rnd_300BLK_110gr_Tracer_Green_EMAG",
            "JCA_30Rnd_300BLK_110gr_Tracer_Yellow_EMAG",
            "JCA_30Rnd_300BLK_110gr_Tracer_IR_EMAG",
            "JCA_30Rnd_300BLK_sand_EMAG",
            "JCA_30Rnd_300BLK_Red_sand_EMAG",
            "JCA_30Rnd_300BLK_Green_sand_EMAG",
            "JCA_30Rnd_300BLK_Yellow_sand_EMAG",
            "JCA_30Rnd_300BLK_IR_sand_EMAG",
            "JCA_30Rnd_300BLK_Tracer_Red_sand_EMAG",
            "JCA_30Rnd_300BLK_Tracer_Green_sand_EMAG",
            "JCA_30Rnd_300BLK_Tracer_Yellow_sand_EMAG",
            "JCA_30Rnd_300BLK_Tracer_IR_sand_EMAG",
            "JCA_30Rnd_300BLK_110gr_sand_EMAG",
            "JCA_30Rnd_300BLK_110gr_Red_sand_EMAG",
            "JCA_30Rnd_300BLK_110gr_Green_sand_EMAG",
            "JCA_30Rnd_300BLK_110gr_Yellow_sand_EMAG",
            "JCA_30Rnd_300BLK_110gr_IR_sand_EMAG",
            "JCA_30Rnd_300BLK_110gr_Tracer_Red_sand_EMAG",
            "JCA_30Rnd_300BLK_110gr_Tracer_Green_sand_EMAG",
            "JCA_30Rnd_300BLK_110gr_Tracer_Yellow_sand_EMAG",
            "JCA_30Rnd_300BLK_110gr_Tracer_IR_sand_EMAG"
        };
        class WeaponSlotsInfo: WeaponSlotsInfo
        {
            mass=68.3; // 3.1kg https://www.heckler-koch.com, JCA 70
        };
        class Single: Single
        {
            dispersion=0.0004; // 2.46 MOA (*0.562*0.000291), 0.562 value from https://github.com/acemod/ACE3/pull/5755, JCA 0.00065 (2.23 MOA)
        };
        class FullAuto: FullAuto
        {
            dispersion=0.0004; // 2.46 MOA (*0.562*0.000291), 0.562 value from https://github.com/acemod/ACE3/pull/5755, JCA 0.00065 (2.23 MOA)
        };
    };
    class JCA_arifle_HK437_VFG_olive_F: JCA_arifle_HK437_VFG_base_F
    {
        ACE_barrelTwist=203.2; // 1:8" https://www.heckler-koch.com/Downloads/Produktinformationen/EN/HK437%20Handbook%20EN.pdf
        ACE_barrelLength=228.6; // 9"
        ACE_railHeightAboveBore=3.71386; // ACE3 checkScopes.sqf
        maxZeroing=700; // distance .300 Blackout 110gr TAP Urban Mach 0.8 (272m/s) ICAO
        initSpeed=-1; // 290, 630m/s according to ACE_muzzleVelocities ICAO conditions (15°C, 1013.25hPa, 0%) and HK437 Handbook https://www.heckler-koch.com/Downloads/Produktinformationen/EN/HK437%20Handbook%20EN.pdf
        magazines[]=
        {
            "JCA_30Rnd_300BLK_EMAG",
            "JCA_30Rnd_300BLK_Red_EMAG",
            "JCA_30Rnd_300BLK_Green_EMAG",
            "JCA_30Rnd_300BLK_Yellow_EMAG",
            "JCA_30Rnd_300BLK_IR_EMAG",
            "JCA_30Rnd_300BLK_Tracer_Red_EMAG",
            "JCA_30Rnd_300BLK_Tracer_Green_EMAG",
            "JCA_30Rnd_300BLK_Tracer_Yellow_EMAG",
            "JCA_30Rnd_300BLK_Tracer_IR_EMAG",
            "JCA_30Rnd_300BLK_110gr_EMAG",
            "JCA_30Rnd_300BLK_110gr_Red_EMAG",
            "JCA_30Rnd_300BLK_110gr_Green_EMAG",
            "JCA_30Rnd_300BLK_110gr_Yellow_EMAG",
            "JCA_30Rnd_300BLK_110gr_IR_EMAG",
            "JCA_30Rnd_300BLK_110gr_Tracer_Red_EMAG",
            "JCA_30Rnd_300BLK_110gr_Tracer_Green_EMAG",
            "JCA_30Rnd_300BLK_110gr_Tracer_Yellow_EMAG",
            "JCA_30Rnd_300BLK_110gr_Tracer_IR_EMAG",
            "JCA_30Rnd_300BLK_sand_EMAG",
            "JCA_30Rnd_300BLK_Red_sand_EMAG",
            "JCA_30Rnd_300BLK_Green_sand_EMAG",
            "JCA_30Rnd_300BLK_Yellow_sand_EMAG",
            "JCA_30Rnd_300BLK_IR_sand_EMAG",
            "JCA_30Rnd_300BLK_Tracer_Red_sand_EMAG",
            "JCA_30Rnd_300BLK_Tracer_Green_sand_EMAG",
            "JCA_30Rnd_300BLK_Tracer_Yellow_sand_EMAG",
            "JCA_30Rnd_300BLK_Tracer_IR_sand_EMAG",
            "JCA_30Rnd_300BLK_110gr_sand_EMAG",
            "JCA_30Rnd_300BLK_110gr_Red_sand_EMAG",
            "JCA_30Rnd_300BLK_110gr_Green_sand_EMAG",
            "JCA_30Rnd_300BLK_110gr_Yellow_sand_EMAG",
            "JCA_30Rnd_300BLK_110gr_IR_sand_EMAG",
            "JCA_30Rnd_300BLK_110gr_Tracer_Red_sand_EMAG",
            "JCA_30Rnd_300BLK_110gr_Tracer_Green_sand_EMAG",
            "JCA_30Rnd_300BLK_110gr_Tracer_Yellow_sand_EMAG",
            "JCA_30Rnd_300BLK_110gr_Tracer_IR_sand_EMAG"
        };
        class WeaponSlotsInfo: WeaponSlotsInfo
        {
            mass=68.3; // 3.1kg https://www.heckler-koch.com, JCA 70
        };
        class Single: Single
        {
            dispersion=0.0004; // 2.46 MOA (*0.562*0.000291), 0.562 value from https://github.com/acemod/ACE3/pull/5755, JCA 0.00065 (2.23 MOA)
        };
        class FullAuto: FullAuto
        {
            dispersion=0.0004; // 2.46 MOA (*0.562*0.000291), 0.562 value from https://github.com/acemod/ACE3/pull/5755, JCA 0.00065 (2.23 MOA)
        };
    };
    class JCA_optic_ARS_base: ItemCore
    {
        ACE_ScopeHeightAboveRail=4.12031; // ACE3 checkScopes.sqf
    };
    class JCA_muzzle_snds_Enhanced_base: ItemCore
    {
        class ItemInfo;
    };
    class JCA_muzzle_snds_300_Enhanced_black: JCA_muzzle_snds_Enhanced_base // Sound Suppressor 7.62mm, muzzle_snds_B
    {
        class ItemInfo: ItemInfo
        {
            class MagazineCoef
            {
                initSpeed=1; // ACE3, JCA 1.05, muzzle_snds_B 1.05
            };
            class AmmoCoef
            {
                hit=1;
                typicalSpeed=1;
                airFriction=1;
                visibleFire=0.3;
                audibleFire=0.04;
                visibleFireTime=0.5;
                audibleFireTime=0.5;
                cost=1;
            };
            class MuzzleCoef
            {
                dispersionCoef=1; // ACE3 0.95, JCA 0.8, muzzle_snds_B 0.8
                artilleryDispersionCoef=1;
                fireLightCoef=0.1;
                recoilCoef=0.95; // ACE3, muzzle_snds_B 1
                recoilProneCoef=0.95; // ACE3, muzzle_snds_B 1
                minRangeCoef=1;
                minRangeProbabCoef=1;
                midRangeCoef=1;
                midRangeProbabCoef=1;
                maxRangeCoef=1;
                maxRangeProbabCoef=1;
            };
        };
    };
    class JCA_muzzle_snds_300_Enhanced_sand: JCA_muzzle_snds_Enhanced_base // Sound Suppressor 7.62mm, muzzle_snds_B
    {
        class ItemInfo: ItemInfo
        {
            class MagazineCoef
            {
                initSpeed=1; // ACE3, JCA 1.05, muzzle_snds_B 1.05
            };
            class AmmoCoef
            {
                hit=1;
                typicalSpeed=1;
                airFriction=1;
                visibleFire=0.3;
                audibleFire=0.04;
                visibleFireTime=0.5;
                audibleFireTime=0.5;
                cost=1;
            };
            class MuzzleCoef
            {
                dispersionCoef=1; // ACE3 0.95, JCA 0.8, muzzle_snds_B 0.8
                artilleryDispersionCoef=1;
                fireLightCoef=0.1;
                recoilCoef=0.95; // ACE3, muzzle_snds_B 1
                recoilProneCoef=0.95; // ACE3, muzzle_snds_B 1
                minRangeCoef=1;
                minRangeProbabCoef=1;
                midRangeCoef=1;
                midRangeProbabCoef=1;
                maxRangeCoef=1;
                maxRangeProbabCoef=1;
            };
        };
    };
    class JCA_muzzle_snds_300_Enhanced_olive: JCA_muzzle_snds_Enhanced_base // Sound Suppressor 7.62mm, muzzle_snds_B
    {
        class ItemInfo: ItemInfo
        {
            class MagazineCoef
            {
                initSpeed=1; // ACE3, JCA 1.05, muzzle_snds_B 1.05
            };
            class AmmoCoef
            {
                hit=1;
                typicalSpeed=1;
                airFriction=1;
                visibleFire=0.3;
                audibleFire=0.04;
                visibleFireTime=0.5;
                audibleFireTime=0.5;
                cost=1;
            };
            class MuzzleCoef
            {
                dispersionCoef=1; // ACE3 0.95, JCA 0.8, muzzle_snds_B 0.8
                artilleryDispersionCoef=1;
                fireLightCoef=0.1;
                recoilCoef=0.95; // ACE3, muzzle_snds_B 1
                recoilProneCoef=0.95; // ACE3, muzzle_snds_B 1
                minRangeCoef=1;
                minRangeProbabCoef=1;
                midRangeCoef=1;
                midRangeProbabCoef=1;
                maxRangeCoef=1;
                maxRangeProbabCoef=1;
            };
        };
    };
};