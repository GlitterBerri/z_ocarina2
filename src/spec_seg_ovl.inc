/*
make_spec_seg_ovl.sh による自動生成ファイルです。
編集およびレジストは禁止されています。
*/

beginseg
	name "ovl_En_GirlA"
	flags OBJECT
	after "ovl_En_Test"
	include "z_en_girlA.o"
	include "z_en_girlA.rel"
endseg

beginseg
	name "ovl_En_Part"
	flags OBJECT
	after "ovl_En_GirlA"
	include "z_en_part.o"
	include "z_en_part.rel"
endseg

beginseg
	name "ovl_En_Light"
	flags OBJECT
	after "ovl_En_Part"
	include "z_en_light.o"
	include "z_en_light.rel"
endseg

beginseg
	name "ovl_En_Door"
	flags OBJECT
	after "ovl_En_Light"
	include "z_en_door.o"
	include "z_en_door.rel"
endseg

beginseg
	name "ovl_En_Box"
	flags OBJECT
	after "ovl_En_Door"
	include "z_en_box.o"
	include "z_en_box.rel"
endseg

beginseg
	name "ovl_En_Poh"
	flags OBJECT
	after "ovl_En_Box"
	include "z_en_poh.o"
	include "z_en_poh.rel"
endseg

beginseg
	name "ovl_En_Okuta"
	flags OBJECT
	after "ovl_En_Poh"
	include "z_en_okuta.o"
	include "z_en_okuta.rel"
endseg

beginseg
	name "ovl_En_Bom"
	flags OBJECT
	after "ovl_En_Okuta"
	include "z_en_bom.o"
	include "z_en_bom.rel"
endseg

beginseg
	name "ovl_En_Wallmas"
	flags OBJECT
	after "ovl_En_Bom"
	include "z_en_wallmas.o"
	include "z_en_wallmas.rel"
endseg

beginseg
	name "ovl_En_Dodongo"
	flags OBJECT
	after "ovl_En_Wallmas"
	include "z_en_dodongo.o"
	include "z_en_dodongo.rel"
endseg

beginseg
	name "ovl_En_Firefly"
	flags OBJECT
	after "ovl_En_Dodongo"
	include "z_en_firefly.o"
	include "z_en_firefly.rel"
endseg

beginseg
	name "ovl_En_Horse"
	flags OBJECT
	after "ovl_En_Firefly"
	include "z_en_horse.o"
	include "z_en_horse.rel"
endseg

beginseg
	name "ovl_En_Arrow"
	flags OBJECT
	after "ovl_En_Horse"
	include "z_en_arrow.o"
	include "z_en_arrow.rel"
endseg

beginseg
	name "ovl_En_Elf"
	flags OBJECT
	after "ovl_En_Arrow"
	include "z_en_elf.o"
	include "z_en_elf.rel"
endseg

beginseg
	name "ovl_En_Niw"
	flags OBJECT
	after "ovl_En_Elf"
	include "z_en_niw.o"
	include "z_en_niw.rel"
endseg

beginseg
	name "ovl_En_Tite"
	flags OBJECT
	after "ovl_En_Niw"
	include "z_en_tite.o"
	include "z_en_tite.rel"
endseg

beginseg
	name "ovl_En_Reeba"
	flags OBJECT
	after "ovl_En_Tite"
	include "z_en_reeba.o"
	include "z_en_reeba.rel"
endseg

beginseg
	name "ovl_En_Peehat"
	flags OBJECT
	after "ovl_En_Reeba"
	include "z_en_peehat.o"
	include "z_en_peehat.rel"
endseg

beginseg
	name "ovl_En_Holl"
	flags OBJECT
	after "ovl_En_Peehat"
	include "z_en_holl.o"
	include "z_en_holl.rel"
endseg

beginseg
	name "ovl_En_Scene_Change"
	flags OBJECT
	after "ovl_En_Holl"
	include "z_en_scene_change.o"
	include "z_en_scene_change.rel"
endseg

beginseg
	name "ovl_En_Zf"
	flags OBJECT
	after "ovl_En_Scene_Change"
	include "z_en_zf.o"
	include "z_en_zf.rel"
endseg

beginseg
	name "ovl_En_Hata"
	flags OBJECT
	after "ovl_En_Zf"
	include "z_en_hata.o"
	include "z_en_hata.rel"
endseg

beginseg
	name "ovl_Boss_Dodongo"
	flags OBJECT
	after "ovl_En_Hata"
	include "z_boss_dodongo.o"
	include "z_boss_dodongo.rel"
endseg

beginseg
	name "ovl_Boss_Goma"
	flags OBJECT
	after "ovl_Boss_Dodongo"
	include "z_boss_goma.o"
	include "z_boss_goma.rel"
endseg

beginseg
	name "ovl_En_Zl1"
	flags OBJECT
	after "ovl_Boss_Goma"
	include "z_en_girlB.o"
	include "z_en_girlB.rel"
endseg

beginseg
	name "ovl_En_Viewer"
	flags OBJECT
	after "ovl_En_Zl1"
	include "z_en_viewer.o"
	include "z_en_viewer.rel"
endseg

beginseg
	name "ovl_En_Goma"
	flags OBJECT
	after "ovl_En_Viewer"
	include "z_en_goma.o"
	include "z_en_goma.rel"
endseg

beginseg
	name "ovl_Bg_Pushbox"
	flags OBJECT
	after "ovl_En_Goma"
	include "z_bg_pushbox.o"
	include "z_bg_pushbox.rel"
endseg

beginseg
	name "ovl_En_Bubble"
	flags OBJECT
	after "ovl_Bg_Pushbox"
	include "z_en_bubble.o"
	include "z_en_bubble.rel"
endseg

beginseg
	name "ovl_Door_Shutter"
	flags OBJECT
	after "ovl_En_Bubble"
	include "z_door_shutter.o"
	include "z_door_shutter.rel"
endseg

beginseg
	name "ovl_En_Dodojr"
	flags OBJECT
	after "ovl_Door_Shutter"
	include "z_en_dodojr.o"
	include "z_en_dodojr.rel"
endseg

beginseg
	name "ovl_En_Bdfire"
	flags OBJECT
	after "ovl_En_Dodojr"
	include "z_en_bdfire.o"
	include "z_en_bdfire.rel"
endseg

beginseg
	name "ovl_En_Boom"
	flags OBJECT
	after "ovl_En_Bdfire"
	include "z_en_boom.o"
	include "z_en_boom.rel"
endseg

beginseg
	name "ovl_En_Torch2"
	flags OBJECT
	after "ovl_En_Boom"
	include "z_en_torch2.o"
	include "z_en_torch2.rel"
endseg

beginseg
	name "ovl_En_Bili"
	flags OBJECT
	after "ovl_En_Torch2"
	include "z_en_bili.o"
	include "z_en_bili.rel"
endseg

beginseg
	name "ovl_En_Tp"
	flags OBJECT
	after "ovl_En_Bili"
	include "z_en_tp.o"
	include "z_en_tp.rel"
endseg

beginseg
	name "ovl_En_St"
	flags OBJECT
	after "ovl_En_Tp"
	include "z_en_st.o"
	include "z_en_st.rel"
endseg

beginseg
	name "ovl_En_Bw"
	flags OBJECT
	after "ovl_En_St"
	include "z_en_bw.o"
	include "z_en_bw.rel"
endseg

beginseg
	name "ovl_En_Eiyer"
	flags OBJECT
	after "ovl_En_Bw"
	include "z_en_eiyer.o"
	include "z_en_eiyer.rel"
endseg

beginseg
	name "ovl_En_River_Sound"
	flags OBJECT
	after "ovl_En_Eiyer"
	include "z_en_river_sound.o"
	include "z_en_river_sound.rel"
endseg

beginseg
	name "ovl_En_Horse_Normal"
	flags OBJECT
	after "ovl_En_River_Sound"
	include "z_en_horse_normal.o"
	include "z_en_horse_normal.rel"
endseg

beginseg
	name "ovl_En_Ossan"
	flags OBJECT
	after "ovl_En_Horse_Normal"
	include "z_en_oB1.o"
	include "z_en_oB1.rel"
endseg

beginseg
	name "ovl_Bg_Treemouth"
	flags OBJECT
	after "ovl_En_Ossan"
	include "z_bg_treemouth.o"
	include "z_bg_treemouth.rel"
endseg

beginseg
	name "ovl_Bg_Dodoago"
	flags OBJECT
	after "ovl_Bg_Treemouth"
	include "z_bg_dodoago.o"
	include "z_bg_dodoago.rel"
endseg

beginseg
	name "ovl_Bg_Hidan_Dalm"
	flags OBJECT
	after "ovl_Bg_Dodoago"
	include "z_bg_hidan_dalm.o"
	include "z_bg_hidan_dalm.rel"
endseg

beginseg
	name "ovl_Bg_Hidan_Hrock"
	flags OBJECT
	after "ovl_Bg_Hidan_Dalm"
	include "z_bg_hidan_hrock.o"
	include "z_bg_hidan_hrock.rel"
endseg

beginseg
	name "ovl_En_Horse_Ganon"
	flags OBJECT
	after "ovl_Bg_Hidan_Hrock"
	include "z_en_horse_ganon.o"
	include "z_en_horse_ganon.rel"
endseg

beginseg
	name "ovl_Bg_Hidan_Rock"
	flags OBJECT
	after "ovl_En_Horse_Ganon"
	include "z_bg_hidan_rock.o"
	include "z_bg_hidan_rock.rel"
endseg

beginseg
	name "ovl_Bg_Hidan_Rsekizou"
	flags OBJECT
	after "ovl_Bg_Hidan_Rock"
	include "z_bg_hidan_rsekizou.o"
	include "z_bg_hidan_rsekizou.rel"
endseg

beginseg
	name "ovl_Bg_Hidan_Sekizou"
	flags OBJECT
	after "ovl_Bg_Hidan_Rsekizou"
	include "z_bg_hidan_sekizou.o"
	include "z_bg_hidan_sekizou.rel"
endseg

beginseg
	name "ovl_Bg_Hidan_Sima"
	flags OBJECT
	after "ovl_Bg_Hidan_Sekizou"
	include "z_bg_hidan_sima.o"
	include "z_bg_hidan_sima.rel"
endseg

beginseg
	name "ovl_Bg_Hidan_Syoku"
	flags OBJECT
	after "ovl_Bg_Hidan_Sima"
	include "z_bg_hidan_syoku.o"
	include "z_bg_hidan_syoku.rel"
endseg

beginseg
	name "ovl_En_Xc"
	flags OBJECT
	after "ovl_Bg_Hidan_Syoku"
	include "z_en_oA2.o"
	include "z_en_oA2.rel"
endseg

beginseg
	name "ovl_Bg_Hidan_Curtain"
	flags OBJECT
	after "ovl_En_Xc"
	include "z_bg_hidan_curtain.o"
	include "z_bg_hidan_curtain.rel"
endseg

beginseg
	name "ovl_Bg_Spot00_Hanebasi"
	flags OBJECT
	after "ovl_Bg_Hidan_Curtain"
	include "z_bg_spot00_hanebasi.o"
	include "z_bg_spot00_hanebasi.rel"
endseg

beginseg
	name "ovl_En_Mb"
	flags OBJECT
	after "ovl_Bg_Spot00_Hanebasi"
	include "z_en_mb.o"
	include "z_en_mb.rel"
endseg

beginseg
	name "ovl_En_Bombf"
	flags OBJECT
	after "ovl_En_Mb"
	include "z_en_bombf.o"
	include "z_en_bombf.rel"
endseg

beginseg
	name "ovl_Bg_Hidan_Firewall"
	flags OBJECT
	after "ovl_En_Bombf"
	include "z_bg_hidan_firewall.o"
	include "z_bg_hidan_firewall.rel"
endseg

beginseg
	name "ovl_Bg_Dy_Yoseizo"
	flags OBJECT
	after "ovl_Bg_Hidan_Firewall"
	include "z_bg_dy_yoseizo.o"
	include "z_bg_dy_yoseizo.rel"
endseg

beginseg
	name "ovl_En_Zl2"
	flags OBJECT
	after "ovl_Bg_Dy_Yoseizo"
	include "z_en_zl2.o"
	include "z_en_zl2.rel"
endseg

beginseg
	name "ovl_Bg_Hidan_Fslift"
	flags OBJECT
	after "ovl_En_Zl2"
	include "z_bg_hidan_fslift.o"
	include "z_bg_hidan_fslift.rel"
endseg

beginseg
	name "ovl_En_OE2"
	flags OBJECT
	after "ovl_Bg_Hidan_Fslift"
	include "z_en_oE2.o"
	include "z_en_oE2.rel"
endseg

beginseg
	name "ovl_Bg_Ydan_Hasi"
	flags OBJECT
	after "ovl_En_OE2"
	include "z_bg_ydan_hasi.o"
	include "z_bg_ydan_hasi.rel"
endseg

beginseg
	name "ovl_Bg_Ydan_Maruta"
	flags OBJECT
	after "ovl_Bg_Ydan_Hasi"
	include "z_bg_ydan_maruta.o"
	include "z_bg_ydan_maruta.rel"
endseg

beginseg
	name "ovl_Boss_Ganondrof"
	flags OBJECT
	after "ovl_Bg_Ydan_Maruta"
	include "z_boss_ganondrof.o"
	include "z_boss_ganondrof.rel"
endseg

beginseg
	name "ovl_En_Am"
	flags OBJECT
	after "ovl_Boss_Ganondrof"
	include "z_en_am.o"
	include "z_en_am.rel"
endseg

beginseg
	name "ovl_En_Dekubaba"
	flags OBJECT
	after "ovl_En_Am"
	include "z_en_dekubaba.o"
	include "z_en_dekubaba.rel"
endseg

beginseg
	name "ovl_En_M_Fire1"
	flags OBJECT
	after "ovl_En_Dekubaba"
	include "z_en_m_fire1.o"
	include "z_en_m_fire1.rel"
endseg

beginseg
	name "ovl_En_M_Thunder"
	flags OBJECT
	after "ovl_En_M_Fire1"
	include "z_en_m_thunder.o"
	include "z_en_m_thunder.rel"
endseg

beginseg
	name "ovl_Bg_Ddan_Jd"
	flags OBJECT
	after "ovl_En_M_Thunder"
	include "z_bg_ddan_jd.o"
	include "z_bg_ddan_jd.rel"
endseg

beginseg
	name "ovl_Bg_Breakwall"
	flags OBJECT
	after "ovl_Bg_Ddan_Jd"
	include "z_bg_breakwall.o"
	include "z_bg_breakwall.rel"
endseg

beginseg
	name "ovl_En_Jj"
	flags OBJECT
	after "ovl_Bg_Breakwall"
	include "z_en_jj.o"
	include "z_en_jj.rel"
endseg

beginseg
	name "ovl_En_Horse_Zelda"
	flags OBJECT
	after "ovl_En_Jj"
	include "z_en_horse_zelda.o"
	include "z_en_horse_zelda.rel"
endseg

beginseg
	name "ovl_Bg_Ddan_Kd"
	flags OBJECT
	after "ovl_En_Horse_Zelda"
	include "z_bg_ddan_kd.o"
	include "z_bg_ddan_kd.rel"
endseg

beginseg
	name "ovl_Door_Warp1"
	flags OBJECT
	after "ovl_Bg_Ddan_Kd"
	include "z_door_warp1.o"
	include "z_door_warp1.rel"
endseg

beginseg
	name "ovl_Obj_Syokudai"
	flags OBJECT
	after "ovl_Door_Warp1"
	include "z_obj_syokudai.o"
	include "z_obj_syokudai.rel"
endseg

beginseg
	name "ovl_Item_B_Heart"
	flags OBJECT
	after "ovl_Obj_Syokudai"
	include "z_item_b_heart.o"
	include "z_item_b_heart.rel"
endseg

beginseg
	name "ovl_En_Dekunuts"
	flags OBJECT
	after "ovl_Item_B_Heart"
	include "z_en_dekunuts.o"
	include "z_en_dekunuts.rel"
endseg

beginseg
	name "ovl_Bg_Menkuri_Kaiten"
	flags OBJECT
	after "ovl_En_Dekunuts"
	include "z_bg_menkuri_kaiten.o"
	include "z_bg_menkuri_kaiten.rel"
endseg

beginseg
	name "ovl_Bg_Menkuri_Eye"
	flags OBJECT
	after "ovl_Bg_Menkuri_Kaiten"
	include "z_bg_menkuri_eye.o"
	include "z_bg_menkuri_eye.rel"
endseg

beginseg
	name "ovl_En_Vali"
	flags OBJECT
	after "ovl_Bg_Menkuri_Eye"
	include "z_en_vali.o"
	include "z_en_vali.rel"
endseg

beginseg
	name "ovl_Bg_Mizu_Movebg"
	flags OBJECT
	after "ovl_En_Vali"
	include "z_bg_mizu_movebg.o"
	include "z_bg_mizu_movebg.rel"
endseg

beginseg
	name "ovl_Bg_Mizu_Water"
	flags OBJECT
	after "ovl_Bg_Mizu_Movebg"
	include "z_bg_mizu_water.o"
	include "z_bg_mizu_water.rel"
endseg

beginseg
	name "ovl_Arms_Hook"
	flags OBJECT
	after "ovl_Bg_Mizu_Water"
	include "z_arms_hook.o"
	include "z_arms_hook.rel"
endseg

beginseg
	name "ovl_En_fHG"
	flags OBJECT
	after "ovl_Arms_Hook"
	include "z_en_fhg.o"
	include "z_en_fhg.rel"
endseg

beginseg
	name "ovl_Bg_Mori_Hineri"
	flags OBJECT
	after "ovl_En_fHG"
	include "z_bg_mori_hineri.o"
	include "z_bg_mori_hineri.rel"
endseg

beginseg
	name "ovl_En_Bb"
	flags OBJECT
	after "ovl_Bg_Mori_Hineri"
	include "z_en_bb.o"
	include "z_en_bb.rel"
endseg

beginseg
	name "ovl_Bg_Toki_Hikari"
	flags OBJECT
	after "ovl_En_Bb"
	include "z_bg_toki_hikari.o"
	include "z_bg_toki_hikari.rel"
endseg

beginseg
	name "ovl_En_Yukabyun"
	flags OBJECT
	after "ovl_Bg_Toki_Hikari"
	include "z_en_yukabyun.o"
	include "z_en_yukabyun.rel"
endseg

beginseg
	name "ovl_Bg_Toki_Swd"
	flags OBJECT
	after "ovl_En_Yukabyun"
	include "z_bg_toki_swd.o"
	include "z_bg_toki_swd.rel"
endseg

beginseg
	name "ovl_En_Fhg_Fire"
	flags OBJECT
	after "ovl_Bg_Toki_Swd"
	include "z_en_fhg_fire.o"
	include "z_en_fhg_fire.rel"
endseg

beginseg
	name "ovl_Bg_Mjin"
	flags OBJECT
	after "ovl_En_Fhg_Fire"
	include "z_bg_mjin.o"
	include "z_bg_mjin.rel"
endseg

beginseg
	name "ovl_Bg_Hidan_Kousi"
	flags OBJECT
	after "ovl_Bg_Mjin"
	include "z_bg_hidan_kousi.o"
	include "z_bg_hidan_kousi.rel"
endseg

beginseg
	name "ovl_Door_Toki"
	flags OBJECT
	after "ovl_Bg_Hidan_Kousi"
	include "z_door_toki.o"
	include "z_door_toki.rel"
endseg

beginseg
	name "ovl_Bg_Hidan_Hamstep"
	flags OBJECT
	after "ovl_Door_Toki"
	include "z_bg_hidan_hamstep.o"
	include "z_bg_hidan_hamstep.rel"
endseg

beginseg
	name "ovl_En_Bird"
	flags OBJECT
	after "ovl_Bg_Hidan_Hamstep"
	include "z_en_bird.o"
	include "z_en_bird.rel"
endseg

beginseg
	name "ovl_En_Wood02"
	flags OBJECT
	after "ovl_En_Bird"
	include "z_en_wood02.o"
	include "z_en_wood02.rel"
endseg

beginseg
	name "ovl_En_Lightbox"
	flags OBJECT
	after "ovl_En_Wood02"
	include "z_en_lbox.o"
	include "z_en_lbox.rel"
endseg

beginseg
	name "ovl_En_Pu_box"
	flags OBJECT
	after "ovl_En_Lightbox"
	include "z_en_pubox.o"
	include "z_en_pubox.rel"
endseg

beginseg
	name "ovl_En_Trap"
	flags OBJECT
	after "ovl_En_Pu_box"
	include "z_en_trap.o"
	include "z_en_trap.rel"
endseg

beginseg
	name "ovl_En_Arow_Trap"
	flags OBJECT
	after "ovl_En_Trap"
	include "z_en_arow_trap.o"
	include "z_en_arow_trap.rel"
endseg

beginseg
	name "ovl_En_Vase"
	flags OBJECT
	after "ovl_En_Arow_Trap"
	include "z_en_vase.o"
	include "z_en_vase.rel"
endseg

beginseg
	name "ovl_En_Ta"
	flags OBJECT
	after "ovl_En_Vase"
	include "z_en_ta.o"
	include "z_en_ta.rel"
endseg

beginseg
	name "ovl_En_Tk"
	flags OBJECT
	after "ovl_En_Ta"
	include "z_en_tk.o"
	include "z_en_tk.rel"
endseg

beginseg
	name "ovl_Bg_Mori_Bigst"
	flags OBJECT
	after "ovl_En_Tk"
	include "z_bg_mori_bigst.o"
	include "z_bg_mori_bigst.rel"
endseg

beginseg
	name "ovl_Bg_Mori_Elevator"
	flags OBJECT
	after "ovl_Bg_Mori_Bigst"
	include "z_bg_mori_elevator.o"
	include "z_bg_mori_elevator.rel"
endseg

beginseg
	name "ovl_Bg_Mori_Kaitenkabe"
	flags OBJECT
	after "ovl_Bg_Mori_Elevator"
	include "z_bg_mori_kaitenkabe.o"
	include "z_bg_mori_kaitenkabe.rel"
endseg

beginseg
	name "ovl_Bg_Mori_Rakkatenjo"
	flags OBJECT
	after "ovl_Bg_Mori_Kaitenkabe"
	include "z_bg_mori_rakkatenjo.o"
	include "z_bg_mori_rakkatenjo.rel"
endseg

beginseg
	name "ovl_En_Vm"
	flags OBJECT
	after "ovl_Bg_Mori_Rakkatenjo"
	include "z_en_vm.o"
	include "z_en_vm.rel"
endseg

beginseg
	name "ovl_Demo_Effect"
	flags OBJECT
	after "ovl_En_Vm"
	include "z_demo_effect.o"
	include "z_demo_effect.rel"
endseg

beginseg
	name "ovl_Demo_Kankyo"
	flags OBJECT
	after "ovl_Demo_Effect"
	include "z_demo_kankyo.o"
	include "z_demo_kankyo.rel"
endseg

beginseg
	name "ovl_Bg_Hidan_Fwbig"
	flags OBJECT
	after "ovl_Demo_Kankyo"
	include "z_bg_hidan_fwbig.o"
	include "z_bg_hidan_fwbig.rel"
endseg

beginseg
	name "ovl_En_Floormas"
	flags OBJECT
	after "ovl_Bg_Hidan_Fwbig"
	include "z_en_floormas.o"
	include "z_en_floormas.rel"
endseg

beginseg
	name "ovl_En_Heishi1"
	flags OBJECT
	after "ovl_En_Floormas"
	include "z_en_heishi1.o"
	include "z_en_heishi1.rel"
endseg

beginseg
	name "ovl_En_Rd"
	flags OBJECT
	after "ovl_En_Heishi1"
	include "z_en_rd.o"
	include "z_en_rd.rel"
endseg

beginseg
	name "ovl_En_Po_Sisters"
	flags OBJECT
	after "ovl_En_Rd"
	include "z_en_po_sisters.o"
	include "z_en_po_sisters.rel"
endseg

beginseg
	name "ovl_Bg_Heavy_Block"
	flags OBJECT
	after "ovl_En_Po_Sisters"
	include "z_bg_heavy_block.o"
	include "z_bg_heavy_block.rel"
endseg

beginseg
	name "ovl_Bg_Po_Event"
	flags OBJECT
	after "ovl_Bg_Heavy_Block"
	include "z_bg_po_event.o"
	include "z_bg_po_event.rel"
endseg

beginseg
	name "ovl_Obj_Mure"
	flags OBJECT
	after "ovl_Bg_Po_Event"
	include "z_obj_mure.o"
	include "z_obj_mure.rel"
endseg

beginseg
	name "ovl_En_Sw"
	flags OBJECT
	after "ovl_Obj_Mure"
	include "z_en_sw.o"
	include "z_en_sw.rel"
endseg

beginseg
	name "ovl_Boss_Fd"
	flags OBJECT
	after "ovl_En_Sw"
	include "z_boss_fd.o"
	include "z_boss_fd.rel"
endseg

beginseg
	name "ovl_Object_Kankyo"
	flags OBJECT
	after "ovl_Boss_Fd"
	include "z_object_kankyo.o"
	include "z_object_kankyo.rel"
endseg

beginseg
	name "ovl_En_Du"
	flags OBJECT
	after "ovl_Object_Kankyo"
	include "z_en_du.o"
	include "z_en_du.rel"
endseg

beginseg
	name "ovl_En_Fd"
	flags OBJECT
	after "ovl_En_Du"
	include "z_en_fd.o"
	include "z_en_fd.rel"
endseg

beginseg
	name "ovl_En_Horse_Link_Child"
	flags OBJECT
	after "ovl_En_Fd"
	include "z_en_horse_link_child.o"
	include "z_en_horse_link_child.rel"
endseg

beginseg
	name "ovl_Door_Ana"
	flags OBJECT
	after "ovl_En_Horse_Link_Child"
	include "z_door_ana.o"
	include "z_door_ana.rel"
endseg

beginseg
	name "ovl_Bg_Spot02_Objects"
	flags OBJECT
	after "ovl_Door_Ana"
	include "z_bg_spot02_objects.o"
	include "z_bg_spot02_objects.rel"
endseg

beginseg
	name "ovl_Bg_Haka"
	flags OBJECT
	after "ovl_Bg_Spot02_Objects"
	include "z_bg_haka.o"
	include "z_bg_haka.rel"
endseg

beginseg
	name "ovl_Magic_Wind"
	flags OBJECT
	after "ovl_Bg_Haka"
	include "z_magic_wind.o"
	include "z_magic_wind.rel"
endseg

beginseg
	name "ovl_Magic_Fire"
	flags OBJECT
	after "ovl_Magic_Wind"
	include "z_magic_fire.o"
	include "z_magic_fire.rel"
endseg

beginseg
	name "ovl_En_Ru1"
	flags OBJECT
	after "ovl_Magic_Fire"
	include "z_en_ru1.o"
	include "z_en_ru1.rel"
endseg

beginseg
	name "ovl_Boss_Fd2"
	flags OBJECT
	after "ovl_En_Ru1"
	include "z_boss_fd2.o"
	include "z_boss_fd2.rel"
endseg

beginseg
	name "ovl_En_Fd_Fire"
	flags OBJECT
	after "ovl_Boss_Fd2"
	include "z_en_fd_fire.o"
	include "z_en_fd_fire.rel"
endseg

beginseg
	name "ovl_En_Dh"
	flags OBJECT
	after "ovl_En_Fd_Fire"
	include "z_en_dh.o"
	include "z_en_dh.rel"
endseg

beginseg
	name "ovl_En_Dha"
	flags OBJECT
	after "ovl_En_Dh"
	include "z_en_dha.o"
	include "z_en_dha.rel"
endseg

beginseg
	name "ovl_En_Rl"
	flags OBJECT
	after "ovl_En_Dha"
	include "z_en_rl.o"
	include "z_en_rl.rel"
endseg

beginseg
	name "ovl_En_Encount1"
	flags OBJECT
	after "ovl_En_Rl"
	include "z_en_encount1.o"
	include "z_en_encount1.rel"
endseg

beginseg
	name "ovl_Demo_Du"
	flags OBJECT
	after "ovl_En_Encount1"
	include "z_demo_du.o"
	include "z_demo_du.rel"
endseg

beginseg
	name "ovl_Demo_Im"
	flags OBJECT
	after "ovl_Demo_Du"
	include "z_demo_im.o"
	include "z_demo_im.rel"
endseg

beginseg
	name "ovl_Demo_Tre_Lgt"
	flags OBJECT
	after "ovl_Demo_Im"
	include "z_demo_tre_lgt.o"
	include "z_demo_tre_lgt.rel"
endseg

beginseg
	name "ovl_En_Fw"
	flags OBJECT
	after "ovl_Demo_Tre_Lgt"
	include "z_en_fw.o"
	include "z_en_fw.rel"
endseg

beginseg
	name "ovl_Bg_Vb_Sima"
	flags OBJECT
	after "ovl_En_Fw"
	include "z_bg_vb_sima.o"
	include "z_bg_vb_sima.rel"
endseg

beginseg
	name "ovl_En_Vb_Ball"
	flags OBJECT
	after "ovl_Bg_Vb_Sima"
	include "z_en_vb_ball.o"
	include "z_en_vb_ball.rel"
endseg

beginseg
	name "ovl_Bg_Haka_Megane"
	flags OBJECT
	after "ovl_En_Vb_Ball"
	include "z_bg_haka_megane.o"
	include "z_bg_haka_megane.rel"
endseg

beginseg
	name "ovl_Bg_Haka_MeganeBG"
	flags OBJECT
	after "ovl_Bg_Haka_Megane"
	include "z_bg_haka_meganeBG.o"
	include "z_bg_haka_meganeBG.rel"
endseg

beginseg
	name "ovl_Bg_Haka_Ship"
	flags OBJECT
	after "ovl_Bg_Haka_MeganeBG"
	include "z_bg_haka_ship.o"
	include "z_bg_haka_ship.rel"
endseg

beginseg
	name "ovl_Bg_Haka_Sgami"
	flags OBJECT
	after "ovl_Bg_Haka_Ship"
	include "z_bg_haka_sgami.o"
	include "z_bg_haka_sgami.rel"
endseg

beginseg
	name "ovl_En_Heishi2"
	flags OBJECT
	after "ovl_Bg_Haka_Sgami"
	include "z_en_heishi2.o"
	include "z_en_heishi2.rel"
endseg

beginseg
	name "ovl_En_Encount2"
	flags OBJECT
	after "ovl_En_Heishi2"
	include "z_en_encount2.o"
	include "z_en_encount2.rel"
endseg

beginseg
	name "ovl_En_Fire_Rock"
	flags OBJECT
	after "ovl_En_Encount2"
	include "z_en_fire_rock.o"
	include "z_en_fire_rock.rel"
endseg

beginseg
	name "ovl_En_Brob"
	flags OBJECT
	after "ovl_En_Fire_Rock"
	include "z_en_brob.o"
	include "z_en_brob.rel"
endseg

beginseg
	name "ovl_Mir_Ray"
	flags OBJECT
	after "ovl_En_Brob"
	include "z_mir_ray.o"
	include "z_mir_ray.rel"
endseg

beginseg
	name "ovl_Bg_Spot09_Obj"
	flags OBJECT
	after "ovl_Mir_Ray"
	include "z_bg_spot09_obj.o"
	include "z_bg_spot09_obj.rel"
endseg

beginseg
	name "ovl_Bg_Spot18_Obj"
	flags OBJECT
	after "ovl_Bg_Spot09_Obj"
	include "z_bg_spot18_obj.o"
	include "z_bg_spot18_obj.rel"
endseg

beginseg
	name "ovl_Boss_Va"
	flags OBJECT
	after "ovl_Bg_Spot18_Obj"
	include "z_boss_va.o"
	include "z_boss_va.rel"
endseg

beginseg
	name "ovl_Bg_Haka_Tubo"
	flags OBJECT
	after "ovl_Boss_Va"
	include "z_bg_haka_tubo.o"
	include "z_bg_haka_tubo.rel"
endseg

beginseg
	name "ovl_Bg_Haka_Trap"
	flags OBJECT
	after "ovl_Bg_Haka_Tubo"
	include "z_bg_haka_trap.o"
	include "z_bg_haka_trap.rel"
endseg

beginseg
	name "ovl_Bg_Haka_Huta"
	flags OBJECT
	after "ovl_Bg_Haka_Trap"
	include "z_bg_haka_huta.o"
	include "z_bg_haka_huta.rel"
endseg

beginseg
	name "ovl_Bg_Haka_Zou"
	flags OBJECT
	after "ovl_Bg_Haka_Huta"
	include "z_bg_haka_zou.o"
	include "z_bg_haka_zou.rel"
endseg

beginseg
	name "ovl_Bg_Spot17_Funen"
	flags OBJECT
	after "ovl_Bg_Haka_Zou"
	include "z_bg_spot17_funen.o"
	include "z_bg_spot17_funen.rel"
endseg

beginseg
	name "ovl_En_Syateki_Itm"
	flags OBJECT
	after "ovl_Bg_Spot17_Funen"
	include "z_en_syateki_itm.o"
	include "z_en_syateki_itm.rel"
endseg

beginseg
	name "ovl_En_Syateki_Man"
	flags OBJECT
	after "ovl_En_Syateki_Itm"
	include "z_en_syateki_man.o"
	include "z_en_syateki_man.rel"
endseg

beginseg
	name "ovl_En_Tana"
	flags OBJECT
	after "ovl_En_Syateki_Man"
	include "z_en_tana.o"
	include "z_en_tana.rel"
endseg

beginseg
	name "ovl_En_Nb"
	flags OBJECT
	after "ovl_En_Tana"
	include "z_en_nb.o"
	include "z_en_nb.rel"
endseg

beginseg
	name "ovl_Boss_Mo"
	flags OBJECT
	after "ovl_En_Nb"
	include "z_boss_mo.o"
	include "z_boss_mo.rel"
endseg

beginseg
	name "ovl_En_Sb"
	flags OBJECT
	after "ovl_Boss_Mo"
	include "z_en_sb.o"
	include "z_en_sb.rel"
endseg

beginseg
	name "ovl_En_Bigokuta"
	flags OBJECT
	after "ovl_En_Sb"
	include "z_en_bigokuta.o"
	include "z_en_bigokuta.rel"
endseg

beginseg
	name "ovl_En_Karebaba"
	flags OBJECT
	after "ovl_En_Bigokuta"
	include "z_en_karebaba.o"
	include "z_en_karebaba.rel"
endseg

beginseg
	name "ovl_Bg_Bdan_Objects"
	flags OBJECT
	after "ovl_En_Karebaba"
	include "z_bg_bdan_objects.o"
	include "z_bg_bdan_objects.rel"
endseg

beginseg
	name "ovl_Demo_Sa"
	flags OBJECT
	after "ovl_Bg_Bdan_Objects"
	include "z_demo_sa.o"
	include "z_demo_sa.rel"
endseg

beginseg
	name "ovl_Demo_Go"
	flags OBJECT
	after "ovl_Demo_Sa"
	include "z_demo_go.o"
	include "z_demo_go.rel"
endseg

beginseg
	name "ovl_En_In"
	flags OBJECT
	after "ovl_Demo_Go"
	include "z_en_in.o"
	include "z_en_in.rel"
endseg

beginseg
	name "ovl_En_Tr"
	flags OBJECT
	after "ovl_En_In"
	include "z_en_tr.o"
	include "z_en_tr.rel"
endseg

beginseg
	name "ovl_Bg_Spot16_Bombstone"
	flags OBJECT
	after "ovl_En_Tr"
	include "z_bg_spot16_bombstone.o"
	include "z_bg_spot16_bombstone.rel"
endseg

beginseg
	name "ovl_Bg_Hidan_Kowarerukabe"
	flags OBJECT
	after "ovl_Bg_Spot16_Bombstone"
	include "z_bg_hidan_kowarerukabe.o"
	include "z_bg_hidan_kowarerukabe.rel"
endseg

beginseg
	name "ovl_Bg_Bombwall"
	flags OBJECT
	after "ovl_Bg_Hidan_Kowarerukabe"
	include "z_bg_bombwall.o"
	include "z_bg_bombwall.rel"
endseg

beginseg
	name "ovl_En_Ru2"
	flags OBJECT
	after "ovl_Bg_Bombwall"
	include "z_en_ru2.o"
	include "z_en_ru2.rel"
endseg

beginseg
	name "ovl_Obj_Dekujr"
	flags OBJECT
	after "ovl_En_Ru2"
	include "z_obj_dekujr.o"
	include "z_obj_dekujr.rel"
endseg

beginseg
	name "ovl_Bg_Mizu_Uzu"
	flags OBJECT
	after "ovl_Obj_Dekujr"
	include "z_bg_mizu_uzu.o"
	include "z_bg_mizu_uzu.rel"
endseg

beginseg
	name "ovl_Bg_Spot06_Objects"
	flags OBJECT
	after "ovl_Bg_Mizu_Uzu"
	include "z_bg_spot06_objects.o"
	include "z_bg_spot06_objects.rel"
endseg

beginseg
	name "ovl_Bg_Ice_Objects"
	flags OBJECT
	after "ovl_Bg_Spot06_Objects"
	include "z_bg_ice_objects.o"
	include "z_bg_ice_objects.rel"
endseg

beginseg
	name "ovl_Bg_Haka_Water"
	flags OBJECT
	after "ovl_Bg_Ice_Objects"
	include "z_bg_haka_water.o"
	include "z_bg_haka_water.rel"
endseg

beginseg
	name "ovl_En_Ma2"
	flags OBJECT
	after "ovl_Bg_Haka_Water"
	include "z_en_ma2.o"
	include "z_en_ma2.rel"
endseg

beginseg
	name "ovl_En_Bom_Chu"
	flags OBJECT
	after "ovl_En_Ma2"
	include "z_en_bom_chu.o"
	include "z_en_bom_chu.rel"
endseg

beginseg
	name "ovl_En_Horse_Game_Check"
	flags OBJECT
	after "ovl_En_Bom_Chu"
	include "z_en_horse_game_check.o"
	include "z_en_horse_game_check.rel"
endseg

beginseg
	name "ovl_Boss_Tw"
	flags OBJECT
	after "ovl_En_Horse_Game_Check"
	include "z_boss_tw.o"
	include "z_boss_tw.rel"
endseg

beginseg
	name "ovl_En_Rr"
	flags OBJECT
	after "ovl_Boss_Tw"
	include "z_en_rr.o"
	include "z_en_rr.rel"
endseg

beginseg
	name "ovl_En_Ba"
	flags OBJECT
	after "ovl_En_Rr"
	include "z_en_ba.o"
	include "z_en_ba.rel"
endseg

beginseg
	name "ovl_En_Bx"
	flags OBJECT
	after "ovl_En_Ba"
	include "z_en_bx.o"
	include "z_en_bx.rel"
endseg

beginseg
	name "ovl_En_Anubice"
	flags OBJECT
	after "ovl_En_Bx"
	include "z_en_anubice.o"
	include "z_en_anubice.rel"
endseg

beginseg
	name "ovl_En_Anubice_Fire"
	flags OBJECT
	after "ovl_En_Anubice"
	include "z_en_anubice_fire.o"
	include "z_en_anubice_fire.rel"
endseg

beginseg
	name "ovl_Bg_Mori_Hashigo"
	flags OBJECT
	after "ovl_En_Anubice_Fire"
	include "z_bg_mori_hashigo.o"
	include "z_bg_mori_hashigo.rel"
endseg

beginseg
	name "ovl_Bg_Mori_Hashira4"
	flags OBJECT
	after "ovl_Bg_Mori_Hashigo"
	include "z_bg_mori_hashira4.o"
	include "z_bg_mori_hashira4.rel"
endseg

beginseg
	name "ovl_Bg_Mori_Idomizu"
	flags OBJECT
	after "ovl_Bg_Mori_Hashira4"
	include "z_bg_mori_idomizu.o"
	include "z_bg_mori_idomizu.rel"
endseg

beginseg
	name "ovl_Bg_Spot16_Doughnut"
	flags OBJECT
	after "ovl_Bg_Mori_Idomizu"
	include "z_bg_spot16_doughnut.o"
	include "z_bg_spot16_doughnut.rel"
endseg

beginseg
	name "ovl_Bg_Bdan_Switch"
	flags OBJECT
	after "ovl_Bg_Spot16_Doughnut"
	include "z_bg_bdan_switch.o"
	include "z_bg_bdan_switch.rel"
endseg

beginseg
	name "ovl_En_Ma1"
	flags OBJECT
	after "ovl_Bg_Bdan_Switch"
	include "z_en_ma1.o"
	include "z_en_ma1.rel"
endseg

beginseg
	name "ovl_Boss_Ganon"
	flags OBJECT
	after "ovl_En_Ma1"
	include "z_boss_ganon.o"
	include "z_boss_ganon.rel"
endseg

beginseg
	name "ovl_Boss_Sst"
	flags OBJECT
	after "ovl_Boss_Ganon"
	include "z_boss_sst.o"
	include "z_boss_sst.rel"
endseg

beginseg
	name "ovl_En_Ny"
	flags OBJECT
	after "ovl_Boss_Sst"
	include "z_en_ny.o"
	include "z_en_ny.rel"
endseg

beginseg
	name "ovl_En_Fr"
	flags OBJECT
	after "ovl_En_Ny"
	include "z_en_fr.o"
	include "z_en_fr.rel"
endseg

beginseg
	name "ovl_Item_Shield"
	flags OBJECT
	after "ovl_En_Fr"
	include "z_item_shield.o"
	include "z_item_shield.rel"
endseg

beginseg
	name "ovl_Bg_Ice_Shelter"
	flags OBJECT
	after "ovl_Item_Shield"
	include "z_bg_ice_shelter.o"
	include "z_bg_ice_shelter.rel"
endseg

beginseg
	name "ovl_En_Ice_Hono"
	flags OBJECT
	after "ovl_Bg_Ice_Shelter"
	include "z_en_ice_hono.o"
	include "z_en_ice_hono.rel"
endseg

beginseg
	name "ovl_Item_Ocarina"
	flags OBJECT
	after "ovl_En_Ice_Hono"
	include "z_item_ocarina.o"
	include "z_item_ocarina.rel"
endseg

beginseg
	name "ovl_Magic_Dark"
	flags OBJECT
	after "ovl_Item_Ocarina"
	include "z_magic_dark.o"
	include "z_magic_dark.rel"
endseg

beginseg
	name "ovl_Demo_6K"
	flags OBJECT
	after "ovl_Magic_Dark"
	include "z_demo_6k.o"
	include "z_demo_6k.rel"
endseg

beginseg
	name "ovl_En_Anubice_Tag"
	flags OBJECT
	after "ovl_Demo_6K"
	include "z_en_anubice_tag.o"
	include "z_en_anubice_tag.rel"
endseg

beginseg
	name "ovl_Bg_Haka_Gate"
	flags OBJECT
	after "ovl_En_Anubice_Tag"
	include "z_bg_haka_gate.o"
	include "z_bg_haka_gate.rel"
endseg

beginseg
	name "ovl_Bg_Spot15_Saku"
	flags OBJECT
	after "ovl_Bg_Haka_Gate"
	include "z_bg_spot15_saku.o"
	include "z_bg_spot15_saku.rel"
endseg

beginseg
	name "ovl_Bg_Jya_Goroiwa"
	flags OBJECT
	after "ovl_Bg_Spot15_Saku"
	include "z_bg_jya_goroiwa.o"
	include "z_bg_jya_goroiwa.rel"
endseg

beginseg
	name "ovl_Bg_Jya_Zurerukabe"
	flags OBJECT
	after "ovl_Bg_Jya_Goroiwa"
	include "z_bg_jya_zurerukabe.o"
	include "z_bg_jya_zurerukabe.rel"
endseg

beginseg
	name "ovl_Bg_Jya_Cobra"
	flags OBJECT
	after "ovl_Bg_Jya_Zurerukabe"
	include "z_bg_jya_cobra.o"
	include "z_bg_jya_cobra.rel"
endseg

beginseg
	name "ovl_Bg_Jya_Kanaami"
	flags OBJECT
	after "ovl_Bg_Jya_Cobra"
	include "z_bg_jya_kanaami.o"
	include "z_bg_jya_kanaami.rel"
endseg

beginseg
	name "ovl_Fishing"
	flags OBJECT
	after "ovl_Bg_Jya_Kanaami"
	include "z_fishing.o"
	include "z_fishing.rel"
endseg

beginseg
	name "ovl_Obj_Oshihiki"
	flags OBJECT
	after "ovl_Fishing"
	include "z_obj_oshihiki.o"
	include "z_obj_oshihiki.rel"
endseg

beginseg
	name "ovl_Bg_Gate_Shutter"
	flags OBJECT
	after "ovl_Obj_Oshihiki"
	include "z_bg_gate_shutter.o"
	include "z_bg_gate_shutter.rel"
endseg

beginseg
	name "ovl_Eff_Dust"
	flags OBJECT
	after "ovl_Bg_Gate_Shutter"
	include "z_eff_dust.o"
	include "z_eff_dust.rel"
endseg

beginseg
	name "ovl_Bg_Spot01_Fusya"
	flags OBJECT
	after "ovl_Eff_Dust"
	include "z_bg_spot01_fusya.o"
	include "z_bg_spot01_fusya.rel"
endseg

beginseg
	name "ovl_Bg_Spot01_Idohashira"
	flags OBJECT
	after "ovl_Bg_Spot01_Fusya"
	include "z_bg_spot01_idohashira.o"
	include "z_bg_spot01_idohashira.rel"
endseg

beginseg
	name "ovl_Bg_Spot01_Idomizu"
	flags OBJECT
	after "ovl_Bg_Spot01_Idohashira"
	include "z_bg_spot01_idomizu.o"
	include "z_bg_spot01_idomizu.rel"
endseg

beginseg
	name "ovl_Bg_Po_Syokudai"
	flags OBJECT
	after "ovl_Bg_Spot01_Idomizu"
	include "z_bg_po_syokudai.o"
	include "z_bg_po_syokudai.rel"
endseg

beginseg
	name "ovl_Bg_Ganon_Otyuka"
	flags OBJECT
	after "ovl_Bg_Po_Syokudai"
	include "z_bg_ganon_otyuka.o"
	include "z_bg_ganon_otyuka.rel"
endseg

beginseg
	name "ovl_Bg_Spot15_Rrbox"
	flags OBJECT
	after "ovl_Bg_Ganon_Otyuka"
	include "z_bg_spot15_rrbox.o"
	include "z_bg_spot15_rrbox.rel"
endseg

beginseg
	name "ovl_Bg_Umajump"
	flags OBJECT
	after "ovl_Bg_Spot15_Rrbox"
	include "z_bg_umajump.o"
	include "z_bg_umajump.rel"
endseg

beginseg
	name "ovl_En_Insect"
	flags OBJECT
	after "ovl_Bg_Umajump"
	include "z_en_mushi.o"
	include "z_en_mushi.rel"
endseg

beginseg
	name "ovl_En_Butte"
	flags OBJECT
	after "ovl_En_Insect"
	include "z_en_choo.o"
	include "z_en_choo.rel"
endseg

beginseg
	name "ovl_En_Fish"
	flags OBJECT
	after "ovl_En_Butte"
	include "z_en_sakana.o"
	include "z_en_sakana.rel"
endseg

beginseg
	name "ovl_Bg_Spot08_Iceblock"
	flags OBJECT
	after "ovl_En_Fish"
	include "z_bg_spot08_iceblock.o"
	include "z_bg_spot08_iceblock.rel"
endseg

beginseg
	name "ovl_Item_Etcetera"
	flags OBJECT
	after "ovl_Bg_Spot08_Iceblock"
	include "z_item_etcetera.o"
	include "z_item_etcetera.rel"
endseg

beginseg
	name "ovl_Arrow_Fire"
	flags OBJECT
	after "ovl_Item_Etcetera"
	include "z_arrow_fire.o"
	include "z_arrow_fire.rel"
endseg

beginseg
	name "ovl_Arrow_Ice"
	flags OBJECT
	after "ovl_Arrow_Fire"
	include "z_arrow_ice.o"
	include "z_arrow_ice.rel"
endseg

beginseg
	name "ovl_Arrow_Light"
	flags OBJECT
	after "ovl_Arrow_Ice"
	include "z_arrow_light.o"
	include "z_arrow_light.rel"
endseg

beginseg
	name "ovl_Obj_Kibako"
	flags OBJECT
	after "ovl_Arrow_Light"
	include "z_obj_kibako.o"
	include "z_obj_kibako.rel"
endseg

beginseg
	name "ovl_Obj_Tsubo"
	flags OBJECT
	after "ovl_Obj_Kibako"
	include "z_obj_tsubo.o"
	include "z_obj_tsubo.rel"
endseg

beginseg
	name "ovl_En_Wonder_Item"
	flags OBJECT
	after "ovl_Obj_Tsubo"
	include "z_en_wonder_item.o"
	include "z_en_wonder_item.rel"
endseg

beginseg
	name "ovl_En_Ik"
	flags OBJECT
	after "ovl_En_Wonder_Item"
	include "z_en_ik.o"
	include "z_en_ik.rel"
endseg

beginseg
	name "ovl_Demo_Ik"
	flags OBJECT
	after "ovl_En_Ik"
	include "z_demo_ik.o"
	include "z_demo_ik.rel"
endseg

beginseg
	name "ovl_En_Skj"
	flags OBJECT
	after "ovl_Demo_Ik"
	include "z_en_skj.o"
	include "z_en_skj.rel"
endseg

beginseg
	name "ovl_En_Skjneedle"
	flags OBJECT
	after "ovl_En_Skj"
	include "z_en_skj_needle.o"
	include "z_en_skj_needle.rel"
endseg

beginseg
	name "ovl_En_G_Switch"
	flags OBJECT
	after "ovl_En_Skjneedle"
	include "z_en_g_switch.o"
	include "z_en_g_switch.rel"
endseg

beginseg
	name "ovl_Demo_Ext"
	flags OBJECT
	after "ovl_En_G_Switch"
	include "z_demo_ext.o"
	include "z_demo_ext.rel"
endseg

beginseg
	name "ovl_Demo_Shd"
	flags OBJECT
	after "ovl_Demo_Ext"
	include "z_demo_shd.o"
	include "z_demo_shd.rel"
endseg

beginseg
	name "ovl_En_Dns"
	flags OBJECT
	after "ovl_Demo_Shd"
	include "z_en_dns.o"
	include "z_en_dns.rel"
endseg

beginseg
	name "ovl_Elf_Msg"
	flags OBJECT
	after "ovl_En_Dns"
	include "z_elf_msg.o"
	include "z_elf_msg.rel"
endseg

beginseg
	name "ovl_En_Honotrap"
	flags OBJECT
	after "ovl_Elf_Msg"
	include "z_en_honotrap.o"
	include "z_en_honotrap.rel"
endseg

beginseg
	name "ovl_En_Tubo_Trap"
	flags OBJECT
	after "ovl_En_Honotrap"
	include "z_en_tubo_trap.o"
	include "z_en_tubo_trap.rel"
endseg

beginseg
	name "ovl_Obj_Ice_Poly"
	flags OBJECT
	after "ovl_En_Tubo_Trap"
	include "z_obj_ice_poly.o"
	include "z_obj_ice_poly.rel"
endseg

beginseg
	name "ovl_Bg_Spot03_Taki"
	flags OBJECT
	after "ovl_Obj_Ice_Poly"
	include "z_bg_spot03_taki.o"
	include "z_bg_spot03_taki.rel"
endseg

beginseg
	name "ovl_Bg_Spot07_Taki"
	flags OBJECT
	after "ovl_Bg_Spot03_Taki"
	include "z_bg_spot07_taki.o"
	include "z_bg_spot07_taki.rel"
endseg

beginseg
	name "ovl_En_Fz"
	flags OBJECT
	after "ovl_Bg_Spot07_Taki"
	include "z_en_fz.o"
	include "z_en_fz.rel"
endseg

beginseg
	name "ovl_En_Po_Relay"
	flags OBJECT
	after "ovl_En_Fz"
	include "z_en_po_relay.o"
	include "z_en_po_relay.rel"
endseg

beginseg
	name "ovl_Bg_Relay_Objects"
	flags OBJECT
	after "ovl_En_Po_Relay"
	include "z_bg_relay_objects.o"
	include "z_bg_relay_objects.rel"
endseg

beginseg
	name "ovl_En_Diving_Game"
	flags OBJECT
	after "ovl_Bg_Relay_Objects"
	include "z_en_diving_game.o"
	include "z_en_diving_game.rel"
endseg

beginseg
	name "ovl_En_Kusa"
	flags OBJECT
	after "ovl_En_Diving_Game"
	include "z_en_kusa.o"
	include "z_en_kusa.rel"
endseg

beginseg
	name "ovl_Obj_Bean"
	flags OBJECT
	after "ovl_En_Kusa"
	include "z_obj_bean.o"
	include "z_obj_bean.rel"
endseg

beginseg
	name "ovl_Obj_Bombiwa"
	flags OBJECT
	after "ovl_Obj_Bean"
	include "z_obj_bombiwa.o"
	include "z_obj_bombiwa.rel"
endseg

beginseg
	name "ovl_Obj_Switch"
	flags OBJECT
	after "ovl_Obj_Bombiwa"
	include "z_obj_switch.o"
	include "z_obj_switch.rel"
endseg

beginseg
	name "ovl_Obj_Elevator"
	flags OBJECT
	after "ovl_Obj_Switch"
	include "z_obj_elevator.o"
	include "z_obj_elevator.rel"
endseg

beginseg
	name "ovl_Obj_Lift"
	flags OBJECT
	after "ovl_Obj_Elevator"
	include "z_obj_lift.o"
	include "z_obj_lift.rel"
endseg

beginseg
	name "ovl_Obj_Hsblock"
	flags OBJECT
	after "ovl_Obj_Lift"
	include "z_obj_hsblock.o"
	include "z_obj_hsblock.rel"
endseg

beginseg
	name "ovl_En_Okarina_Tag"
	flags OBJECT
	after "ovl_Obj_Hsblock"
	include "z_en_okarina_tag.o"
	include "z_en_okarina_tag.rel"
endseg

beginseg
	name "ovl_En_Yabusame_Mark"
	flags OBJECT
	after "ovl_En_Okarina_Tag"
	include "z_en_yabusame_mark.o"
	include "z_en_yabusame_mark.rel"
endseg

beginseg
	name "ovl_En_Goroiwa"
	flags OBJECT
	after "ovl_En_Yabusame_Mark"
	include "z_en_gr.o"
	include "z_en_gr.rel"
endseg

beginseg
	name "ovl_En_Ex_Ruppy"
	flags OBJECT
	after "ovl_En_Goroiwa"
	include "z_en_ex_ruppy.o"
	include "z_en_ex_ruppy.rel"
endseg

beginseg
	name "ovl_En_Toryo"
	flags OBJECT
	after "ovl_En_Ex_Ruppy"
	include "z_en_toryo.o"
	include "z_en_toryo.rel"
endseg

beginseg
	name "ovl_En_Daiku"
	flags OBJECT
	after "ovl_En_Toryo"
	include "z_en_daiku.o"
	include "z_en_daiku.rel"
endseg

beginseg
	name "ovl_En_Nwc"
	flags OBJECT
	after "ovl_En_Daiku"
	include "z_en_nwc.o"
	include "z_en_nwc.rel"
endseg

beginseg
	name "ovl_En_Blkobj"
	flags OBJECT
	after "ovl_En_Nwc"
	include "z_en_blkobj.o"
	include "z_en_blkobj.rel"
endseg

beginseg
	name "ovl_Item_Inbox"
	flags OBJECT
	after "ovl_En_Blkobj"
	include "z_item_inbox.o"
	include "z_item_inbox.rel"
endseg

beginseg
	name "ovl_En_Ge1"
	flags OBJECT
	after "ovl_Item_Inbox"
	include "z_en_ge1.o"
	include "z_en_ge1.rel"
endseg

beginseg
	name "ovl_Obj_Blockstop"
	flags OBJECT
	after "ovl_En_Ge1"
	include "z_obj_blockstop.o"
	include "z_obj_blockstop.rel"
endseg

beginseg
	name "ovl_En_Sda"
	flags OBJECT
	after "ovl_Obj_Blockstop"
	include "z_en_sda.o"
	include "z_en_sda.rel"
endseg

beginseg
	name "ovl_En_Clear_Tag"
	flags OBJECT
	after "ovl_En_Sda"
	include "z_en_clear_tag.o"
	include "z_en_clear_tag.rel"
endseg

beginseg
	name "ovl_En_Niw_Lady"
	flags OBJECT
	after "ovl_En_Clear_Tag"
	include "z_en_niw_lady.o"
	include "z_en_niw_lady.rel"
endseg

beginseg
	name "ovl_En_Gm"
	flags OBJECT
	after "ovl_En_Niw_Lady"
	include "z_en_gm.o"
	include "z_en_gm.rel"
endseg

beginseg
	name "ovl_En_Ms"
	flags OBJECT
	after "ovl_En_Gm"
	include "z_en_ms.o"
	include "z_en_ms.rel"
endseg

beginseg
	name "ovl_En_Hs"
	flags OBJECT
	after "ovl_En_Ms"
	include "z_en_hs.o"
	include "z_en_hs.rel"
endseg

beginseg
	name "ovl_Bg_Ingate"
	flags OBJECT
	after "ovl_En_Hs"
	include "z_bg_ingate.o"
	include "z_bg_ingate.rel"
endseg

beginseg
	name "ovl_En_Kanban"
	flags OBJECT
	after "ovl_Bg_Ingate"
	include "z_en_kanban.o"
	include "z_en_kanban.rel"
endseg

beginseg
	name "ovl_En_Heishi3"
	flags OBJECT
	after "ovl_En_Kanban"
	include "z_en_heishi3.o"
	include "z_en_heishi3.rel"
endseg

beginseg
	name "ovl_En_Syateki_Niw"
	flags OBJECT
	after "ovl_En_Heishi3"
	include "z_en_syateki_niw.o"
	include "z_en_syateki_niw.rel"
endseg

beginseg
	name "ovl_En_Attack_Niw"
	flags OBJECT
	after "ovl_En_Syateki_Niw"
	include "z_en_attack_niw.o"
	include "z_en_attack_niw.rel"
endseg

beginseg
	name "ovl_Bg_Spot01_Idosoko"
	flags OBJECT
	after "ovl_En_Attack_Niw"
	include "z_bg_spot01_idosoko.o"
	include "z_bg_spot01_idosoko.rel"
endseg

beginseg
	name "ovl_En_Sa"
	flags OBJECT
	after "ovl_Bg_Spot01_Idosoko"
	include "z_en_sa.o"
	include "z_en_sa.rel"
endseg

beginseg
	name "ovl_En_Wonder_Talk"
	flags OBJECT
	after "ovl_En_Sa"
	include "z_en_wonder_talk.o"
	include "z_en_wonder_talk.rel"
endseg

beginseg
	name "ovl_Bg_Gjyo_Bridge"
	flags OBJECT
	after "ovl_En_Wonder_Talk"
	include "z_bg_gjyo_bridge.o"
	include "z_bg_gjyo_bridge.rel"
endseg

beginseg
	name "ovl_En_Ds"
	flags OBJECT
	after "ovl_Bg_Gjyo_Bridge"
	include "z_en_ds.o"
	include "z_en_ds.rel"
endseg

beginseg
	name "ovl_En_Mk"
	flags OBJECT
	after "ovl_En_Ds"
	include "z_en_mk.o"
	include "z_en_mk.rel"
endseg

beginseg
	name "ovl_En_Bom_Bowl_Man"
	flags OBJECT
	after "ovl_En_Mk"
	include "z_en_bom_bowl_man.o"
	include "z_en_bom_bowl_man.rel"
endseg

beginseg
	name "ovl_En_Bom_Bowl_Pit"
	flags OBJECT
	after "ovl_En_Bom_Bowl_Man"
	include "z_en_bom_bowl_pit.o"
	include "z_en_bom_bowl_pit.rel"
endseg

beginseg
	name "ovl_En_Owl"
	flags OBJECT
	after "ovl_En_Bom_Bowl_Pit"
	include "z_en_owl.o"
	include "z_en_owl.rel"
endseg

beginseg
	name "ovl_En_Ishi"
	flags OBJECT
	after "ovl_En_Owl"
	include "z_en_ishi.o"
	include "z_en_ishi.rel"
endseg

beginseg
	name "ovl_Obj_Hana"
	flags OBJECT
	after "ovl_En_Ishi"
	include "z_obj_hana.o"
	include "z_obj_hana.rel"
endseg

beginseg
	name "ovl_Obj_Lightswitch"
	flags OBJECT
	after "ovl_Obj_Hana"
	include "z_obj_lightswitch.o"
	include "z_obj_lightswitch.rel"
endseg

beginseg
	name "ovl_Obj_Mure2"
	flags OBJECT
	after "ovl_Obj_Lightswitch"
	include "z_obj_mure2.o"
	include "z_obj_mure2.rel"
endseg

beginseg
	name "ovl_En_Go"
	flags OBJECT
	after "ovl_Obj_Mure2"
	include "z_en_go.o"
	include "z_en_go.rel"
endseg

beginseg
	name "ovl_En_Fu"
	flags OBJECT
	after "ovl_En_Go"
	include "z_en_fu.o"
	include "z_en_fu.rel"
endseg

beginseg
	name "ovl_En_Changer"
	flags OBJECT
	after "ovl_En_Fu"
	include "z_en_changer.o"
	include "z_en_changer.rel"
endseg

beginseg
	name "ovl_Bg_Jya_Megami"
	flags OBJECT
	after "ovl_En_Changer"
	include "z_bg_jya_megami.o"
	include "z_bg_jya_megami.rel"
endseg

beginseg
	name "ovl_Bg_Jya_Lift"
	flags OBJECT
	after "ovl_Bg_Jya_Megami"
	include "z_bg_jya_lift.o"
	include "z_bg_jya_lift.rel"
endseg

beginseg
	name "ovl_Bg_Jya_Bigmirror"
	flags OBJECT
	after "ovl_Bg_Jya_Lift"
	include "z_bg_jya_bigmirror.o"
	include "z_bg_jya_bigmirror.rel"
endseg

beginseg
	name "ovl_Bg_Jya_Bombchuiwa"
	flags OBJECT
	after "ovl_Bg_Jya_Bigmirror"
	include "z_bg_jya_bombchuiwa.o"
	include "z_bg_jya_bombchuiwa.rel"
endseg

beginseg
	name "ovl_Bg_Jya_Amishutter"
	flags OBJECT
	after "ovl_Bg_Jya_Bombchuiwa"
	include "z_bg_jya_amishutter.o"
	include "z_bg_jya_amishutter.rel"
endseg

beginseg
	name "ovl_Bg_Jya_Bombiwa"
	flags OBJECT
	after "ovl_Bg_Jya_Amishutter"
	include "z_bg_jya_bombiwa.o"
	include "z_bg_jya_bombiwa.rel"
endseg

beginseg
	name "ovl_Bg_Spot18_Basket"
	flags OBJECT
	after "ovl_Bg_Jya_Bombiwa"
	include "z_bg_spot18_basket.o"
	include "z_bg_spot18_basket.rel"
endseg

beginseg
	name "ovl_En_Ganon_Organ"
	flags OBJECT
	after "ovl_Bg_Spot18_Basket"
	include "z_en_ganon_organ.o"
	include "z_en_ganon_organ.rel"
endseg

beginseg
	name "ovl_En_Siofuki"
	flags OBJECT
	after "ovl_En_Ganon_Organ"
	include "z_en_siofuki.o"
	include "z_en_siofuki.rel"
endseg

beginseg
	name "ovl_En_Stream"
	flags OBJECT
	after "ovl_En_Siofuki"
	include "z_en_stream.o"
	include "z_en_stream.rel"
endseg

beginseg
	name "ovl_En_Mm"
	flags OBJECT
	after "ovl_En_Stream"
	include "z_en_mm.o"
	include "z_en_mm.rel"
endseg

beginseg
	name "ovl_En_Ko"
	flags OBJECT
	after "ovl_En_Mm"
	include "z_en_ko.o"
	include "z_en_ko.rel"
endseg

beginseg
	name "ovl_En_Kz"
	flags OBJECT
	after "ovl_En_Ko"
	include "z_en_kz.o"
	include "z_en_kz.rel"
endseg

beginseg
	name "ovl_En_Weather_Tag"
	flags OBJECT
	after "ovl_En_Kz"
	include "z_en_weather_tag.o"
	include "z_en_weather_tag.rel"
endseg

beginseg
	name "ovl_Bg_Sst_Floor"
	flags OBJECT
	after "ovl_En_Weather_Tag"
	include "z_bg_sst_floor.o"
	include "z_bg_sst_floor.rel"
endseg

beginseg
	name "ovl_En_Ani"
	flags OBJECT
	after "ovl_Bg_Sst_Floor"
	include "z_en_ani.o"
	include "z_en_ani.rel"
endseg

beginseg
	name "ovl_En_Ex_Item"
	flags OBJECT
	after "ovl_En_Ani"
	include "z_en_ex_item.o"
	include "z_en_ex_item.rel"
endseg

beginseg
	name "ovl_Bg_Jya_Ironobj"
	flags OBJECT
	after "ovl_En_Ex_Item"
	include "z_bg_jya_ironobj.o"
	include "z_bg_jya_ironobj.rel"
endseg

beginseg
	name "ovl_En_Js"
	flags OBJECT
	after "ovl_Bg_Jya_Ironobj"
	include "z_en_js.o"
	include "z_en_js.rel"
endseg

beginseg
	name "ovl_En_Jsjutan"
	flags OBJECT
	after "ovl_En_Js"
	include "z_en_jsjutan.o"
	include "z_en_jsjutan.rel"
endseg

beginseg
	name "ovl_En_Cs"
	flags OBJECT
	after "ovl_En_Jsjutan"
	include "z_en_cs.o"
	include "z_en_cs.rel"
endseg

beginseg
	name "ovl_En_Md"
	flags OBJECT
	after "ovl_En_Cs"
	include "z_en_md.o"
	include "z_en_md.rel"
endseg

beginseg
	name "ovl_En_Hy"
	flags OBJECT
	after "ovl_En_Md"
	include "z_en_hy.o"
	include "z_en_hy.rel"
endseg

beginseg
	name "ovl_En_Ganon_Mant"
	flags OBJECT
	after "ovl_En_Hy"
	include "z_en_ganon_mant.o"
	include "z_en_ganon_mant.rel"
endseg

beginseg
	name "ovl_En_Okarina_Effect"
	flags OBJECT
	after "ovl_En_Ganon_Mant"
	include "z_en_okarina_effect.o"
	include "z_en_okarina_effect.rel"
endseg

beginseg
	name "ovl_En_Mag"
	flags OBJECT
	after "ovl_En_Okarina_Effect"
	include "z_en_mag.o"
	include "z_en_mag.rel"
endseg

beginseg
	name "ovl_Door_Gerudo"
	flags OBJECT
	after "ovl_En_Mag"
	include "z_door_gerudo.o"
	include "z_door_gerudo.rel"
endseg

beginseg
	name "ovl_Elf_Msg2"
	flags OBJECT
	after "ovl_Door_Gerudo"
	include "z_elf_msg2.o"
	include "z_elf_msg2.rel"
endseg

beginseg
	name "ovl_Demo_Gt"
	flags OBJECT
	after "ovl_Elf_Msg2"
	include "z_demo_gt.o"
	include "z_demo_gt.rel"
endseg

beginseg
	name "ovl_En_Po_Field"
	flags OBJECT
	after "ovl_Demo_Gt"
	include "z_en_po_field.o"
	include "z_en_po_field.rel"
endseg

beginseg
	name "ovl_Efc_Erupc"
	flags OBJECT
	after "ovl_En_Po_Field"
	include "z_efc_erupc.o"
	include "z_efc_erupc.rel"
endseg

beginseg
	name "ovl_Bg_Zg"
	flags OBJECT
	after "ovl_Efc_Erupc"
	include "z_bg_zg.o"
	include "z_bg_zg.rel"
endseg

beginseg
	name "ovl_En_Heishi4"
	flags OBJECT
	after "ovl_Bg_Zg"
	include "z_en_heishi4.o"
	include "z_en_heishi4.rel"
endseg

beginseg
	name "ovl_En_Zl3"
	flags OBJECT
	after "ovl_En_Heishi4"
	include "z_en_zl3.o"
	include "z_en_zl3.rel"
endseg

beginseg
	name "ovl_Boss_Ganon2"
	flags OBJECT
	after "ovl_En_Zl3"
	include "z_boss_ganon2.o"
	include "z_boss_ganon2.rel"
endseg

beginseg
	name "ovl_En_Kakasi"
	flags OBJECT
	after "ovl_Boss_Ganon2"
	include "z_en_kakasi.o"
	include "z_en_kakasi.rel"
endseg

beginseg
	name "ovl_En_Takara_Man"
	flags OBJECT
	after "ovl_En_Kakasi"
	include "z_en_takara_man.o"
	include "z_en_takara_man.rel"
endseg

beginseg
	name "ovl_Obj_Makeoshihiki"
	flags OBJECT
	after "ovl_En_Takara_Man"
	include "z_obj_makeoshihiki.o"
	include "z_obj_makeoshihiki.rel"
endseg

beginseg
	name "ovl_Oceff_Spot"
	flags OBJECT
	after "ovl_Obj_Makeoshihiki"
	include "z_oceff_spot.o"
	include "z_oceff_spot.rel"
endseg

beginseg
	name "ovl_End_Title"
	flags OBJECT
	after "ovl_Oceff_Spot"
	include "z_end_title.o"
	include "z_end_title.rel"
endseg

beginseg
	name "ovl_En_Torch"
	flags OBJECT
	after "ovl_End_Title"
	include "z_en_torch.o"
	include "z_en_torch.rel"
endseg

beginseg
	name "ovl_Demo_Ec"
	flags OBJECT
	after "ovl_En_Torch"
	include "z_demo_ec.o"
	include "z_demo_ec.rel"
endseg

beginseg
	name "ovl_Shot_Sun"
	flags OBJECT
	after "ovl_Demo_Ec"
	include "z_shot_sun.o"
	include "z_shot_sun.rel"
endseg

beginseg
	name "ovl_En_Dy_Extra"
	flags OBJECT
	after "ovl_Shot_Sun"
	include "z_en_dy_extra.o"
	include "z_en_dy_extra.rel"
endseg

beginseg
	name "ovl_En_Wonder_Talk2"
	flags OBJECT
	after "ovl_En_Dy_Extra"
	include "z_en_wonder_talk2.o"
	include "z_en_wonder_talk2.rel"
endseg

beginseg
	name "ovl_En_Ge2"
	flags OBJECT
	after "ovl_En_Wonder_Talk2"
	include "z_en_ge2.o"
	include "z_en_ge2.rel"
endseg

beginseg
	name "ovl_Obj_Roomtimer"
	flags OBJECT
	after "ovl_En_Ge2"
	include "z_obj_roomtimer.o"
	include "z_obj_roomtimer.rel"
endseg

beginseg
	name "ovl_En_Ssh"
	flags OBJECT
	after "ovl_Obj_Roomtimer"
	include "z_en_ssh.o"
	include "z_en_ssh.rel"
endseg

beginseg
	name "ovl_En_Sth"
	flags OBJECT
	after "ovl_En_Ssh"
	include "z_en_sth.o"
	include "z_en_sth.rel"
endseg

beginseg
	name "ovl_Oceff_Wipe"
	flags OBJECT
	after "ovl_En_Sth"
	include "z_oceff_wipe.o"
	include "z_oceff_wipe.rel"
endseg

beginseg
	name "ovl_Effect_Ss_Dust"
	flags OBJECT
	after "ovl_Oceff_Wipe"
	include "z_eff_ss_dust.o"
	include "z_eff_ss_dust.rel"
endseg

beginseg
	name "ovl_Effect_Ss_KiraKira"
	flags OBJECT
	after "ovl_Effect_Ss_Dust"
	include "z_eff_ss_kirakira.o"
	include "z_eff_ss_kirakira.rel"
endseg

beginseg
	name "ovl_Effect_Ss_Bomb"
	flags OBJECT
	after "ovl_Effect_Ss_KiraKira"
	include "z_eff_ss_bomb.o"
	include "z_eff_ss_bomb.rel"
endseg

beginseg
	name "ovl_Effect_Ss_Bomb2"
	flags OBJECT
	after "ovl_Effect_Ss_Bomb"
	include "z_eff_ss_bomb2.o"
	include "z_eff_ss_bomb2.rel"
endseg

beginseg
	name "ovl_Effect_Ss_Blast"
	flags OBJECT
	after "ovl_Effect_Ss_Bomb2"
	include "z_eff_ss_blast.o"
	include "z_eff_ss_blast.rel"
endseg

beginseg
	name "ovl_Effect_Ss_G_Spk"
	flags OBJECT
	after "ovl_Effect_Ss_Blast"
	include "z_eff_ss_g_spk.o"
	include "z_eff_ss_g_spk.rel"
endseg

beginseg
	name "ovl_Effect_Ss_D_Fire"
	flags OBJECT
	after "ovl_Effect_Ss_G_Spk"
	include "z_eff_ss_d_fire.o"
	include "z_eff_ss_d_fire.rel"
endseg

beginseg
	name "ovl_Effect_Ss_Bubble"
	flags OBJECT
	after "ovl_Effect_Ss_D_Fire"
	include "z_eff_ss_bubble.o"
	include "z_eff_ss_bubble.rel"
endseg

beginseg
	name "ovl_Effect_Ss_G_Ripple"
	flags OBJECT
	after "ovl_Effect_Ss_Bubble"
	include "z_eff_ss_g_ripple.o"
	include "z_eff_ss_g_ripple.rel"
endseg

beginseg
	name "ovl_Effect_Ss_G_Splash"
	flags OBJECT
	after "ovl_Effect_Ss_G_Ripple"
	include "z_eff_ss_g_splash.o"
	include "z_eff_ss_g_splash.rel"
endseg

beginseg
	name "ovl_Effect_Ss_G_Magma"
	flags OBJECT
	after "ovl_Effect_Ss_G_Splash"
	include "z_eff_ss_g_magma.o"
	include "z_eff_ss_g_magma.rel"
endseg

beginseg
	name "ovl_Effect_Ss_G_Fire"
	flags OBJECT
	after "ovl_Effect_Ss_G_Magma"
	include "z_eff_ss_g_fire.o"
	include "z_eff_ss_g_fire.rel"
endseg

beginseg
	name "ovl_Effect_Ss_Lightning"
	flags OBJECT
	after "ovl_Effect_Ss_G_Fire"
	include "z_eff_ss_lightning.o"
	include "z_eff_ss_lightning.rel"
endseg

beginseg
	name "ovl_Effect_Ss_Dt_Bubble"
	flags OBJECT
	after "ovl_Effect_Ss_Lightning"
	include "z_eff_ss_dt_bubble.o"
	include "z_eff_ss_dt_bubble.rel"
endseg

beginseg
	name "ovl_Effect_Ss_Hahen"
	flags OBJECT
	after "ovl_Effect_Ss_Dt_Bubble"
	include "z_eff_hahen.o"
	include "z_eff_hahen.rel"
endseg

beginseg
	name "ovl_Effect_Ss_Stick"
	flags OBJECT
	after "ovl_Effect_Ss_Hahen"
	include "z_eff_ss_stick.o"
	include "z_eff_ss_stick.rel"
endseg

beginseg
	name "ovl_Effect_Ss_Sibuki"
	flags OBJECT
	after "ovl_Effect_Ss_Stick"
	include "z_eff_ss_sibuki.o"
	include "z_eff_ss_sibuki.rel"
endseg

beginseg
	name "ovl_Effect_Ss_Sibuki2"
	flags OBJECT
	after "ovl_Effect_Ss_Sibuki"
	include "z_eff_ss_sibuki2.o"
	include "z_eff_ss_sibuki2.rel"
endseg

beginseg
	name "ovl_Effect_Ss_G_Magma2"
	flags OBJECT
	after "ovl_Effect_Ss_Sibuki2"
	include "z_eff_ss_g_magma2.o"
	include "z_eff_ss_g_magma2.rel"
endseg

beginseg
	name "ovl_Effect_Ss_Stone1"
	flags OBJECT
	after "ovl_Effect_Ss_G_Magma2"
	include "z_eff_ss_stone1.o"
	include "z_eff_ss_stone1.rel"
endseg

beginseg
	name "ovl_Effect_Ss_HitMark"
	flags OBJECT
	after "ovl_Effect_Ss_Stone1"
	include "z_eff_ss_hitmark.o"
	include "z_eff_ss_hitmark.rel"
endseg

beginseg
	name "ovl_Effect_Ss_Fhg_Flash"
	flags OBJECT
	after "ovl_Effect_Ss_HitMark"
	include "z_eff_fhg_flash.o"
	include "z_eff_fhg_flash.rel"
endseg

beginseg
	name "ovl_Effect_Ss_K_Fire"
	flags OBJECT
	after "ovl_Effect_Ss_Fhg_Flash"
	include "z_eff_k_fire.o"
	include "z_eff_k_fire.rel"
endseg

beginseg
	name "ovl_Effect_Ss_Solder_Srch_Ball"
	flags OBJECT
	after "ovl_Effect_Ss_K_Fire"
	include "z_eff_ss_solder_srch_ball.o"
	include "z_eff_ss_solder_srch_ball.rel"
endseg

beginseg
	name "ovl_Effect_Ss_Kakera"
	flags OBJECT
	after "ovl_Effect_Ss_Solder_Srch_Ball"
	include "z_eff_kakera.o"
	include "z_eff_kakera.rel"
endseg

beginseg
	name "ovl_Effect_Ss_Ice_Piece"
	flags OBJECT
	after "ovl_Effect_Ss_Kakera"
	include "z_eff_ice_piece.o"
	include "z_eff_ice_piece.rel"
endseg

beginseg
	name "ovl_Effect_Ss_En_Ice"
	flags OBJECT
	after "ovl_Effect_Ss_Ice_Piece"
	include "z_eff_en_ice.o"
	include "z_eff_en_ice.rel"
endseg

beginseg
	name "ovl_Effect_Ss_Fire_Tail"
	flags OBJECT
	after "ovl_Effect_Ss_En_Ice"
	include "z_eff_fire_tail.o"
	include "z_eff_fire_tail.rel"
endseg

beginseg
	name "ovl_Effect_Ss_En_Fire"
	flags OBJECT
	after "ovl_Effect_Ss_Fire_Tail"
	include "z_eff_en_fire.o"
	include "z_eff_en_fire.rel"
endseg

beginseg
	name "ovl_Effect_Ss_Extra"
	flags OBJECT
	after "ovl_Effect_Ss_En_Fire"
	include "z_eff_ss_extra.o"
	include "z_eff_ss_extra.rel"
endseg

beginseg
	name "ovl_Effect_Ss_Fcircle"
	flags OBJECT
	after "ovl_Effect_Ss_Extra"
	include "z_eff_fcircle.o"
	include "z_eff_fcircle.rel"
endseg

beginseg
	name "ovl_Effect_Ss_Dead_Db"
	flags OBJECT
	after "ovl_Effect_Ss_Fcircle"
	include "z_eff_ss_dead_db.o"
	include "z_eff_ss_dead_db.rel"
endseg

beginseg
	name "ovl_Effect_Ss_Dead_Dd"
	flags OBJECT
	after "ovl_Effect_Ss_Dead_Db"
	include "z_eff_ss_dead_dd.o"
	include "z_eff_ss_dead_dd.rel"
endseg

beginseg
	name "ovl_Effect_Ss_Dead_Ds"
	flags OBJECT
	after "ovl_Effect_Ss_Dead_Dd"
	include "z_eff_ss_dead_ds.o"
	include "z_eff_ss_dead_ds.rel"
endseg

beginseg
	name "ovl_Effect_Ss_Dead_Sound"
	flags OBJECT
	after "ovl_Effect_Ss_Dead_Ds"
	include "z_eff_ss_dead_sound.o"
	include "z_eff_ss_dead_sound.rel"
endseg

beginseg
	name "ovl_Oceff_Storm"
	flags OBJECT
	after "ovl_Effect_Ss_Dead_Sound"
	include "z_oceff_storm.o"
	include "z_oceff_storm.rel"
endseg

beginseg
	name "ovl_En_Weiyer"
	flags OBJECT
	after "ovl_Oceff_Storm"
	include "z_en_weiyer.o"
	include "z_en_weiyer.rel"
endseg

beginseg
	name "ovl_Bg_Spot05_Soko"
	flags OBJECT
	after "ovl_En_Weiyer"
	include "z_bg_spot05_soko.o"
	include "z_bg_spot05_soko.rel"
endseg

beginseg
	name "ovl_Bg_Jya_1flift"
	flags OBJECT
	after "ovl_Bg_Spot05_Soko"
	include "z_bg_jya_1flift.o"
	include "z_bg_jya_1flift.rel"
endseg

beginseg
	name "ovl_Bg_Jya_Haheniron"
	flags OBJECT
	after "ovl_Bg_Jya_1flift"
	include "z_bg_jya_haheniron.o"
	include "z_bg_jya_haheniron.rel"
endseg

beginseg
	name "ovl_Bg_Spot12_Gate"
	flags OBJECT
	after "ovl_Bg_Jya_Haheniron"
	include "z_bg_spot12_gate.o"
	include "z_bg_spot12_gate.rel"
endseg

beginseg
	name "ovl_Bg_Spot12_Saku"
	flags OBJECT
	after "ovl_Bg_Spot12_Gate"
	include "z_bg_spot12_saku.o"
	include "z_bg_spot12_saku.rel"
endseg

beginseg
	name "ovl_En_Hintnuts"
	flags OBJECT
	after "ovl_Bg_Spot12_Saku"
	include "z_en_hintnuts.o"
	include "z_en_hintnuts.rel"
endseg

beginseg
	name "ovl_En_Nutsball"
	flags OBJECT
	after "ovl_En_Hintnuts"
	include "z_en_nutsball.o"
	include "z_en_nutsball.rel"
endseg

beginseg
	name "ovl_Bg_Spot00_Break"
	flags OBJECT
	after "ovl_En_Nutsball"
	include "z_bg_spot00_break.o"
	include "z_bg_spot00_break.rel"
endseg

beginseg
	name "ovl_En_Shopnuts"
	flags OBJECT
	after "ovl_Bg_Spot00_Break"
	include "z_en_shopnuts.o"
	include "z_en_shopnuts.rel"
endseg

beginseg
	name "ovl_En_It"
	flags OBJECT
	after "ovl_En_Shopnuts"
	include "z_en_it.o"
	include "z_en_it.rel"
endseg

beginseg
	name "ovl_En_GeldB"
	flags OBJECT
	after "ovl_En_It"
	include "z_en_geldB.o"
	include "z_en_geldB.rel"
endseg

beginseg
	name "ovl_Oceff_Wipe2"
	flags OBJECT
	after "ovl_En_GeldB"
	include "z_oceff_wipe2.o"
	include "z_oceff_wipe2.rel"
endseg

beginseg
	name "ovl_Oceff_Wipe3"
	flags OBJECT
	after "ovl_Oceff_Wipe2"
	include "z_oceff_wipe3.o"
	include "z_oceff_wipe3.rel"
endseg

beginseg
	name "ovl_En_Niw_Girl"
	flags OBJECT
	after "ovl_Oceff_Wipe3"
	include "z_en_niw_girl.o"
	include "z_en_niw_girl.rel"
endseg

beginseg
	name "ovl_En_Dog"
	flags OBJECT
	after "ovl_En_Niw_Girl"
	include "z_en_dog.o"
	include "z_en_dog.rel"
endseg

beginseg
	name "ovl_En_Si"
	flags OBJECT
	after "ovl_En_Dog"
	include "z_en_si.o"
	include "z_en_si.rel"
endseg

beginseg
	name "ovl_Bg_Spot01_Objects2"
	flags OBJECT
	after "ovl_En_Si"
	include "z_bg_spot01_objects2.o"
	include "z_bg_spot01_objects2.rel"
endseg

beginseg
	name "ovl_Obj_Comb"
	flags OBJECT
	after "ovl_Bg_Spot01_Objects2"
	include "z_obj_comb.o"
	include "z_obj_comb.rel"
endseg

beginseg
	name "ovl_Bg_Spot11_Bakudankabe"
	flags OBJECT
	after "ovl_Obj_Comb"
	include "z_bg_spot11_bakudankabe.o"
	include "z_bg_spot11_bakudankabe.rel"
endseg

beginseg
	name "ovl_Obj_Kibako2"
	flags OBJECT
	after "ovl_Bg_Spot11_Bakudankabe"
	include "z_obj_kibako2.o"
	include "z_obj_kibako2.rel"
endseg

beginseg
	name "ovl_En_Dnt_Demo"
	flags OBJECT
	after "ovl_Obj_Kibako2"
	include "z_en_dnt_demo.o"
	include "z_en_dnt_demo.rel"
endseg

beginseg
	name "ovl_En_Dnt_Jiji"
	flags OBJECT
	after "ovl_En_Dnt_Demo"
	include "z_en_dnt_jiji.o"
	include "z_en_dnt_jiji.rel"
endseg

beginseg
	name "ovl_En_Dnt_Nomal"
	flags OBJECT
	after "ovl_En_Dnt_Jiji"
	include "z_en_dnt_nomal.o"
	include "z_en_dnt_nomal.rel"
endseg

beginseg
	name "ovl_En_Guest"
	flags OBJECT
	after "ovl_En_Dnt_Nomal"
	include "z_en_guest.o"
	include "z_en_guest.rel"
endseg

beginseg
	name "ovl_Bg_Bom_Guard"
	flags OBJECT
	after "ovl_En_Guest"
	include "z_bg_bom_guard.o"
	include "z_bg_bom_guard.rel"
endseg

beginseg
	name "ovl_En_Hs2"
	flags OBJECT
	after "ovl_Bg_Bom_Guard"
	include "z_en_hs2.o"
	include "z_en_hs2.rel"
endseg

beginseg
	name "ovl_Demo_Kekkai"
	flags OBJECT
	after "ovl_En_Hs2"
	include "z_demo_kekkai.o"
	include "z_demo_kekkai.rel"
endseg

beginseg
	name "ovl_Bg_Spot08_Bakudankabe"
	flags OBJECT
	after "ovl_Demo_Kekkai"
	include "z_bg_spot08_bakudankabe.o"
	include "z_bg_spot08_bakudankabe.rel"
endseg

beginseg
	name "ovl_Bg_Spot17_Bakudankabe"
	flags OBJECT
	after "ovl_Bg_Spot08_Bakudankabe"
	include "z_bg_spot17_bakudankabe.o"
	include "z_bg_spot17_bakudankabe.rel"
endseg

beginseg
	name "ovl_Obj_Mure3"
	flags OBJECT
	after "ovl_Bg_Spot17_Bakudankabe"
	include "z_obj_mure3.o"
	include "z_obj_mure3.rel"
endseg

beginseg
	name "ovl_En_Tg"
	flags OBJECT
	after "ovl_Obj_Mure3"
	include "z_en_tg.o"
	include "z_en_tg.rel"
endseg

beginseg
	name "ovl_En_Mu"
	flags OBJECT
	after "ovl_En_Tg"
	include "z_en_mu.o"
	include "z_en_mu.rel"
endseg

beginseg
	name "ovl_En_Go2"
	flags OBJECT
	after "ovl_En_Mu"
	include "z_en_go2.o"
	include "z_en_go2.rel"
endseg

beginseg
	name "ovl_En_Wf"
	flags OBJECT
	after "ovl_En_Go2"
	include "z_en_wf.o"
	include "z_en_wf.rel"
endseg

beginseg
	name "ovl_En_Skb"
	flags OBJECT
	after "ovl_En_Wf"
	include "z_en_skb.o"
	include "z_en_skb.rel"
endseg

beginseg
	name "ovl_Demo_Gj"
	flags OBJECT
	after "ovl_En_Skb"
	include "z_demo_gj.o"
	include "z_demo_gj.rel"
endseg

beginseg
	name "ovl_Demo_Geff"
	flags OBJECT
	after "ovl_Demo_Gj"
	include "z_demo_geff.o"
	include "z_demo_geff.rel"
endseg

beginseg
	name "ovl_Bg_Gnd_Firemeiro"
	flags OBJECT
	after "ovl_Demo_Geff"
	include "z_bg_gnd_firemeiro.o"
	include "z_bg_gnd_firemeiro.rel"
endseg

beginseg
	name "ovl_Bg_Gnd_Darkmeiro"
	flags OBJECT
	after "ovl_Bg_Gnd_Firemeiro"
	include "z_bg_gnd_darkmeiro.o"
	include "z_bg_gnd_darkmeiro.rel"
endseg

beginseg
	name "ovl_Bg_Gnd_Soulmeiro"
	flags OBJECT
	after "ovl_Bg_Gnd_Darkmeiro"
	include "z_bg_gnd_soulmeiro.o"
	include "z_bg_gnd_soulmeiro.rel"
endseg

beginseg
	name "ovl_Bg_Gnd_Nisekabe"
	flags OBJECT
	after "ovl_Bg_Gnd_Soulmeiro"
	include "z_bg_gnd_nisekabe.o"
	include "z_bg_gnd_nisekabe.rel"
endseg

beginseg
	name "ovl_Bg_Gnd_Iceblock"
	flags OBJECT
	after "ovl_Bg_Gnd_Nisekabe"
	include "z_bg_gnd_iceblock.o"
	include "z_bg_gnd_iceblock.rel"
endseg

beginseg
	name "ovl_Bg_Ydan_Sp"
	flags OBJECT
	after "ovl_Bg_Gnd_Iceblock"
	include "z_bg_ydan_sp.o"
	include "z_bg_ydan_sp.rel"
endseg

beginseg
	name "ovl_En_Gb"
	flags OBJECT
	after "ovl_Bg_Ydan_Sp"
	include "z_en_gb.o"
	include "z_en_gb.rel"
endseg

beginseg
	name "ovl_En_Gs"
	flags OBJECT
	after "ovl_En_Gb"
	include "z_en_gs.o"
	include "z_en_gs.rel"
endseg

beginseg
	name "ovl_Bg_Mizu_Bwall"
	flags OBJECT
	after "ovl_En_Gs"
	include "z_bg_mizu_bwall.o"
	include "z_bg_mizu_bwall.rel"
endseg

beginseg
	name "ovl_Bg_Mizu_Shutter"
	flags OBJECT
	after "ovl_Bg_Mizu_Bwall"
	include "z_bg_mizu_shutter.o"
	include "z_bg_mizu_shutter.rel"
endseg

beginseg
	name "ovl_En_Daiku_Kakariko"
	flags OBJECT
	after "ovl_Bg_Mizu_Shutter"
	include "z_en_daiku_kakariko.o"
	include "z_en_daiku_kakariko.rel"
endseg

beginseg
	name "ovl_Bg_Bowl_Wall"
	flags OBJECT
	after "ovl_En_Daiku_Kakariko"
	include "z_bg_bowl_wall.o"
	include "z_bg_bowl_wall.rel"
endseg

beginseg
	name "ovl_En_Wall_Tubo"
	flags OBJECT
	after "ovl_Bg_Bowl_Wall"
	include "z_en_wall_tubo.o"
	include "z_en_wall_tubo.rel"
endseg

beginseg
	name "ovl_En_Po_Desert"
	flags OBJECT
	after "ovl_En_Wall_Tubo"
	include "z_en_po_desert.o"
	include "z_en_po_desert.rel"
endseg

beginseg
	name "ovl_En_Crow"
	flags OBJECT
	after "ovl_En_Po_Desert"
	include "z_en_crow.o"
	include "z_en_crow.rel"
endseg

beginseg
	name "ovl_Door_Killer"
	flags OBJECT
	after "ovl_En_Crow"
	include "z_door_killer.o"
	include "z_door_killer.rel"
endseg

beginseg
	name "ovl_Bg_Spot11_Oasis"
	flags OBJECT
	after "ovl_Door_Killer"
	include "z_bg_spot11_oasis.o"
	include "z_bg_spot11_oasis.rel"
endseg

beginseg
	name "ovl_Bg_Spot18_Futa"
	flags OBJECT
	after "ovl_Bg_Spot11_Oasis"
	include "z_bg_spot18_futa.o"
	include "z_bg_spot18_futa.rel"
endseg

beginseg
	name "ovl_Bg_Spot18_Shutter"
	flags OBJECT
	after "ovl_Bg_Spot18_Futa"
	include "z_bg_spot18_shutter.o"
	include "z_bg_spot18_shutter.rel"
endseg

beginseg
	name "ovl_En_Ma3"
	flags OBJECT
	after "ovl_Bg_Spot18_Shutter"
	include "z_en_ma3.o"
	include "z_en_ma3.rel"
endseg

beginseg
	name "ovl_En_Cow"
	flags OBJECT
	after "ovl_En_Ma3"
	include "z_en_cow.o"
	include "z_en_cow.rel"
endseg

beginseg
	name "ovl_Bg_Ice_Turara"
	flags OBJECT
	after "ovl_En_Cow"
	include "z_bg_ice_turara.o"
	include "z_bg_ice_turara.rel"
endseg

beginseg
	name "ovl_Bg_Ice_Shutter"
	flags OBJECT
	after "ovl_Bg_Ice_Turara"
	include "z_bg_ice_shutter.o"
	include "z_bg_ice_shutter.rel"
endseg

beginseg
	name "ovl_En_Kakasi2"
	flags OBJECT
	after "ovl_Bg_Ice_Shutter"
	include "z_en_kakasi2.o"
	include "z_en_kakasi2.rel"
endseg

beginseg
	name "ovl_En_Kakasi3"
	flags OBJECT
	after "ovl_En_Kakasi2"
	include "z_en_kakasi3.o"
	include "z_en_kakasi3.rel"
endseg

beginseg
	name "ovl_Oceff_Wipe4"
	flags OBJECT
	after "ovl_En_Kakasi3"
	include "z_oceff_wipe4.o"
	include "z_oceff_wipe4.rel"
endseg

beginseg
	name "ovl_En_Eg"
	flags OBJECT
	after "ovl_Oceff_Wipe4"
	include "z_en_eg.o"
	include "z_en_eg.rel"
endseg

beginseg
	name "ovl_Bg_Menkuri_Nisekabe"
	flags OBJECT
	after "ovl_En_Eg"
	include "z_bg_menkuri_nisekabe.o"
	include "z_bg_menkuri_nisekabe.rel"
endseg

beginseg
	name "ovl_En_Zo"
	flags OBJECT
	after "ovl_Bg_Menkuri_Nisekabe"
	include "z_en_zo.o"
	include "z_en_zo.rel"
endseg

beginseg
	name "ovl_Effect_Ss_Ice_Smoke"
	flags OBJECT
	after "ovl_En_Zo"
	include "z_eff_ss_ice_smoke.o"
	include "z_eff_ss_ice_smoke.rel"
endseg

beginseg
	name "ovl_Obj_Makekinsuta"
	flags OBJECT
	after "ovl_Effect_Ss_Ice_Smoke"
	include "z_obj_makekinsuta.o"
	include "z_obj_makekinsuta.rel"
endseg

beginseg
	name "ovl_En_Ge3"
	flags OBJECT
	after "ovl_Obj_Makekinsuta"
	include "z_en_ge3.o"
	include "z_en_ge3.rel"
endseg

beginseg
	name "ovl_Obj_Timeblock"
	flags OBJECT
	after "ovl_En_Ge3"
	include "z_obj_timeblock.o"
	include "z_obj_timeblock.rel"
endseg

beginseg
	name "ovl_Obj_Hamishi"
	flags OBJECT
	after "ovl_Obj_Timeblock"
	include "z_obj_hamishi.o"
	include "z_obj_hamishi.rel"
endseg

beginseg
	name "ovl_En_Zl4"
	flags OBJECT
	after "ovl_Obj_Hamishi"
	include "z_en_zl4.o"
	include "z_en_zl4.rel"
endseg

beginseg
	name "ovl_En_Mm2"
	flags OBJECT
	after "ovl_En_Zl4"
	include "z_en_mm2.o"
	include "z_en_mm2.rel"
endseg

beginseg
	name "ovl_Bg_Jya_Block"
	flags OBJECT
	after "ovl_En_Mm2"
	include "z_bg_jya_block.o"
	include "z_bg_jya_block.rel"
endseg

beginseg
	name "ovl_Obj_Warp2block"
	flags OBJECT
	after "ovl_Bg_Jya_Block"
	include "z_obj_warp2block.o"
	include "z_obj_warp2block.rel"
endseg
