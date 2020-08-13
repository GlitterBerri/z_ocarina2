# 1 "../spec"
 






























































































































































































































































































































































































































































































































































































































































































































































































































































# 1 "../boot.h"

# 833 "../spec"
# 1 "../sys_segment.h"
 































































































































































 





 







 











 


 


 


 
 




 
 




 


 
 



 
 







 
 


 
























# 834 "../spec"


 
 
 
 
 
 
 


 


 


 
 
 
 
 
 
 


 
 
 
 
 
 

 



beginseg
	name "boot"
	flags BOOT OBJECT
	entry boot
	stack bootStack + 1024 
	address 0x80000400  
	include "bootsegment.o"


















	include "$(ROOT)/usr/lib/PR/rspboot.o"




	include "$(ZELDA_ROOT)/lib/CIC6105/test.o"  

	 
	include "version.o"
endseg


beginseg 				name "dmadata" 			flags OBJECT 			after           "boot" 			align  16 			include              "z_std_dma_data.o" 	endseg  


 


beginseg 				name    "Audiobank" 		flags   OBJECT 			number    1		include  "$(ZELDA_ROOT)/lib/audio/ZeldaAudio_banks.o" 	endseg 



beginseg 				name    "Audioseq" 		flags   OBJECT 			number     1		include  "$(ZELDA_ROOT)/lib/audio/ZeldaAudio_music.o" 	endseg 

beginseg 				name    "Audiotable" 		flags   OBJECT 			number   1		include  "$(ZELDA_ROOT)/lib/audio/ZeldaAudio_table.o" 	endseg 


 



beginseg 				name    "kanji" 		flags   OBJECT 			number   		10		include  	"kan.o" 		romalign 0x1000		endseg 


beginseg 				name    "link_animetion" 		flags   OBJECT 			number         7		include "$(ZELDA_ROOT)/data/Link_anime_data.o" 		romalign 0x1000		endseg 

 












beginseg 				name    "icon_item_static" 		flags   OBJECT 			number   		8		include  	 "$(ZELDA_ROOT)/data/icon_item.o" 		romalign 0x1000		endseg 
beginseg 				name    "icon_item_24_static" 		flags   OBJECT 			number   		9		include  	 "$(ZELDA_ROOT)/data/icon_item_24.o" 		romalign 0x1000		endseg 
beginseg 				name    "icon_item_field_static" 		flags   OBJECT 			number  	12		include  	 "$(ZELDA_ROOT)/data/icon_item_field.o" 		romalign 0x1000		endseg 
beginseg 				name    "icon_item_dungeon_static" 		flags   OBJECT 			number   	12		include  	 "$(ZELDA_ROOT)/data/icon_item_dungeon.o" 		romalign 0x1000		endseg 
beginseg 				name    "icon_item_gameover_static" 		flags   OBJECT 			number   	12		include  	 "$(ZELDA_ROOT)/data/icon_item_gameover.o" 		romalign 0x1000		endseg 
beginseg 				name    "icon_item_jpn_static" 		flags   OBJECT 			number   	13		include  "$(ZELDA_ROOT)/data/icon_item_jpn.o" 		romalign 0x1000		endseg 
beginseg 				name    "icon_item_nes_static" 		flags   OBJECT 			number   	13		include  "$(ZELDA_ROOT)/data/icon_item_nes.o" 		romalign 0x1000		endseg 






beginseg 				name    "item_name_static" 		flags   OBJECT 			number   		10		include  	 "$(ZELDA_ROOT)/data/item_name.o" 		romalign 0x1000		endseg 
beginseg 				name    "map_name_static" 		flags   OBJECT 			number   		11		include  		 "$(ZELDA_ROOT)/data/map_name.o" 		romalign 0x1000		endseg 



 





beginseg 				name    "do_action_static" 		flags   OBJECT 			number   		7		include  	 "$(ZELDA_ROOT)/data/do_action_idx.o" 		romalign 0x1000		endseg 


 


beginseg 				name    "message_static" 		flags   OBJECT 			number   		7		include  	 "$(ZELDA_ROOT)/data/fukidashi.o" 		romalign 0x1000		endseg 
beginseg 				name    "message_texture_static" 		flags   OBJECT 			number  	9		include  	 "$(ZELDA_ROOT)/data/texture.o" 		romalign 0x1000		endseg 







beginseg 				name    "nes_font_static" 		flags   OBJECT 			number  		10		include  	 "$(ZELDA_ROOT)/data/font_e.o" 		romalign 0x1000		endseg 
beginseg 				name    "message_data_static" 		flags   OBJECT 			number   		8		include  	 "$(ZELDA_ROOT)/data/message.o" 		romalign 0x1000		endseg 
beginseg 				name    "nes_message_data_static" 		flags   OBJECT 			number   	7		include  	 "$(ZELDA_ROOT)/data/nes_c.o" 		romalign 0x1000		endseg 
beginseg 				name    "staff_message_data_static" 		flags   OBJECT 			number   	7		include  	 "$(ZELDA_ROOT)/data/staff_c.o" 		romalign 0x1000		endseg 


 


beginseg 				name    "map_grand_static" 		flags   OBJECT 			number   		11		include  		 "$(ZELDA_ROOT)/data/map_grand.o" 		romalign 0x1000		endseg 











beginseg 				name    "map_48x85_static" 		flags   OBJECT 			number   		11		include  		 "$(ZELDA_ROOT)/data/map_48x85.o" 		romalign 0x1000		endseg 
beginseg 				name    "map_i_static" 		flags   OBJECT 			number   		11		include  		 "$(ZELDA_ROOT)/data/map_i.o" 		romalign 0x1000		endseg 


 


 




beginseg
	name "code"
	flags OBJECT
	after "dmadata"

	include "codesegment.o"
	include "z_vr_box_segment.o"

	 
	include "$(ZELDA_ROOT)/lib/audio/audio_hb.o"
	include "$(ZELDA_ROOT)/lib/audio/audio_hm.o"
	include "$(ZELDA_ROOT)/lib/audio/audio_hs.o"
	include "$(ZELDA_ROOT)/lib/audio/audio_hw.o"

	 
	include "$(ZELDA_ROOT)/lib/audio/aspMain.o"



        include "$(ZELDA_ROOT)/lib/ucode/F3DZEX2_2.08J_PosLight_001109/gspF3DZEX2.NoN_PosLight.fifo.o"




	include "$(ZELDA_ROOT)/lib/ucode/usr.lib.PR.safe/gspS2DEX2.fifo.o"
	include "$(ZELDA_ROOT)/lib/ucode/jpgDRGBA16.o"  

endseg

beginseg 				name "zbuffer" 			flags OBJECT 			after          "code" 			align  64 			include             "sys_zb.o" 	endseg  
beginseg 				name "fifobuffer" 			flags OBJECT 			after        "zbuffer" 			align  16 			include           "sys_fifo_buffer.o" 	endseg  
beginseg 				name "yieldbuffer" 			flags OBJECT 			after       "fifobuffer" 			align  16 			include        "sys_yield_buffer.o" 	endseg  
beginseg 				name "dramstackbuffer" 			flags OBJECT 			after   "yieldbuffer" 			align  16 			include       "sys_dram_stack.o" 	endseg  
beginseg 				name "SystemDynamic" 			flags OBJECT 			after     "dramstackbuffer" 			align  16 			include   "sys_dynamic.o" 	endseg  
beginseg 				name "Audioheap" 			flags OBJECT 			after         "SystemDynamic" 			align  16 			include     "$(ZELDA_ROOT)/lib/audio/audioheap.o" 	endseg  
beginseg 				name "SystemHeap" 			flags OBJECT 			after        "Audioheap" 			align  16 			include         "sys_heap.o" 	endseg  





 


beginseg
	name "ovl_title"
	flags OBJECT
	address 0x80800000
	include "z_title.o"
	include "z_title.rel"
endseg

beginseg
	name "ovl_select"
	flags OBJECT
	after "ovl_title"
	include "z_select_segment.o"
	include "z_select_segment.rel"
endseg

beginseg
	name "ovl_opening"
	flags OBJECT
	after "ovl_select"
	include "z_opening.o"
	include "z_opening.rel"
endseg

beginseg
	after "ovl_opening" name "ovl_file_choose"

	flags OBJECT
	include "z_file_choose_segment.o"
	include "z_file_choose_segment.rel"
endseg

beginseg
	after "ovl_file_choose"  name "ovl_kaleido_scope"


	flags OBJECT
	include "z_kaleido_segment.o"
	include "z_kaleido_segment.rel"
endseg

beginseg
	after "ovl_kaleido_scope"  name "ovl_player_actor"


	flags OBJECT
	include "z_player.o"
	include "z_player.rel"
endseg

beginseg
	after "ovl_player_actor"  name "ovl_map_mark_data"


	flags OBJECT
	include "z_map_mark_data.o"
	include "z_map_mark_data.rel"
endseg

beginseg
	after "ovl_map_mark_data"  name "ovl_En_Test"


	flags OBJECT
	include "z_en_test.o"
	include "z_en_test.rel"
endseg

 



# 5 "../spec_seg_ovl.inc"

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
# 1130 "../spec"


# 1 "../spec.segment"
 






























































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































beginseg 				name    "rcp_cfb" 		flags   OBJECT 			number   15		include  "rcp_cfb.o" 		romalign 0x1000		endseg 
beginseg 				name    "rcp_zb" 		flags   OBJECT 			number   14		include  "rcp_zb.o" 		romalign 0x1000		endseg 





beginseg 				name    "gameplay_keep" 		flags   OBJECT 			number   	   4		include           "$(ZELDA_ROOT)/data/keep.o" 		romalign 0x1000		endseg 

beginseg 				name    "gameplay_field_keep" 		flags   OBJECT 			number       5		include  "$(ZELDA_ROOT)/data/Field_keep.o" 		romalign 0x1000		endseg 
beginseg 				name    "gameplay_dangeon_keep" 		flags   OBJECT 			number     5		include  "$(ZELDA_ROOT)/data/Dangeon_keep.o" 		romalign 0x1000		endseg 

beginseg 				name    "gameplay_object_exchange_static" 		flags   OBJECT 			number   6		include  "$(ZELDA_ROOT)/data/shape/gameplay_object_exchange/gameplay_object_exchange.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_link_boy" 		flags   OBJECT 			number    	6		include "$(ZELDA_ROOT)/data/Link_boy.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_link_child" 		flags   OBJECT 			number    	6		include "$(ZELDA_ROOT)/data/Link_child.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_box" 		flags   OBJECT 			number  	  	6		include "$(ZELDA_ROOT)/data/Box.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_human" 		flags   OBJECT 			number    	6		include "$(ZELDA_ROOT)/data/Human.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_okuta" 		flags   OBJECT 			number    	6		include "$(ZELDA_ROOT)/data/Oc.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_poh" 		flags   OBJECT 			number    		6		include "$(ZELDA_ROOT)/data/Po.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_wallmaster" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/Wm.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_dy_obj" 		flags   OBJECT 			number   	6		include "$(ZELDA_ROOT)/data/dy_obj.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_firefly" 		flags   OBJECT 			number   	6		include "$(ZELDA_ROOT)/data/Ff.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_dodongo" 		flags   OBJECT 			number   	6		include "$(ZELDA_ROOT)/data/Dodongo.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_fire" 		flags   OBJECT 			number    	6		include "$(ZELDA_ROOT)/data/Fire.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_niw" 		flags   OBJECT 			number    		6		include "$(ZELDA_ROOT)/data/Niw.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_tite" 		flags   OBJECT 			number    	6		include "$(ZELDA_ROOT)/data/Tite.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_reeba" 		flags   OBJECT 			number    	6		include "$(ZELDA_ROOT)/data/Reeba.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_peehat" 		flags   OBJECT 			number    	6		include "$(ZELDA_ROOT)/data/Peehat.o" 		romalign 0x1000		endseg 



beginseg 				name    "object_kingdodongo" 		flags   OBJECT 			number   	6		include "$(ZELDA_ROOT)/data/Kdodongo.o" 		romalign 0x1000		endseg 

beginseg 				name    "object_horse" 		flags   OBJECT 			number   	6		include "$(ZELDA_ROOT)/data/Horse.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_zf" 		flags   OBJECT 			number  	 	6		include "$(ZELDA_ROOT)/data/Zf.o" 		romalign 0x1000		endseg 



beginseg 				name    "object_goma" 		flags   OBJECT 			number  	 	6		include "$(ZELDA_ROOT)/data/Go.o" 		romalign 0x1000		endseg 

beginseg 				name    "object_zl1" 		flags   OBJECT 			number  	 	6		include "$(ZELDA_ROOT)/data/Zl1.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gol" 		flags   OBJECT 			number  	 	6		include "$(ZELDA_ROOT)/data/Gol.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_bubble" 		flags   OBJECT 			number   	6		include "$(ZELDA_ROOT)/data/Bubble.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_dodojr" 		flags   OBJECT 			number   	6		include "$(ZELDA_ROOT)/data/Dodojr.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_torch2" 		flags   OBJECT 			number   	6		include "$(ZELDA_ROOT)/data/Torch2.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_bl" 		flags   OBJECT 			number  	 	6		include "$(ZELDA_ROOT)/data/Bl.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_tp" 		flags   OBJECT 			number  	 	6		include "$(ZELDA_ROOT)/data/Tp.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_oA1" 		flags   OBJECT 			number  	 	6		include "$(ZELDA_ROOT)/data/OAX.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_st" 		flags   OBJECT 			number  	 	6		include "$(ZELDA_ROOT)/data/St.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_bw" 		flags   OBJECT 			number  	 	6		include "$(ZELDA_ROOT)/data/Bw.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_ei" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/Ei.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_horse_normal" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/Horse_Normal.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_oB1" 		flags   OBJECT 			number  	 	6		include "$(ZELDA_ROOT)/data/OBX.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_o_anime" 		flags   OBJECT 			number   	6		include "$(ZELDA_ROOT)/data/O_anime.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_spot04_objects" 		flags   OBJECT 			number  6		include "$(ZELDA_ROOT)/data/spot04_objects.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_ddan_objects" 		flags   OBJECT 			number    6		include "$(ZELDA_ROOT)/data/ddan_objects.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_hidan_objects" 		flags   OBJECT 			number    6		include "$(ZELDA_ROOT)/data/hidan_objects.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_horse_ganon" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/Horse_Ganon.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_oA2" 		flags   OBJECT 			number  	 	6		include "$(ZELDA_ROOT)/data/OA2.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_spot00_objects" 		flags   OBJECT 			number    6		include "$(ZELDA_ROOT)/data/spot00_objects.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_mb" 		flags   OBJECT 			number  	 	6		include "$(ZELDA_ROOT)/data/Mb.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_bombf" 		flags   OBJECT 			number  	 	6		include "$(ZELDA_ROOT)/data/Bombf.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_sk2" 		flags   OBJECT 			number  	 	6		include "$(ZELDA_ROOT)/data/Sk2.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_oE1" 		flags   OBJECT 			number  	 	6		include "$(ZELDA_ROOT)/data/OE1.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_oE_anime" 		flags   OBJECT 			number   	6		include "$(ZELDA_ROOT)/data/OE_anime.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_oE2" 		flags   OBJECT 			number  	 	6		include "$(ZELDA_ROOT)/data/OE2.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_ydan_objects" 		flags   OBJECT 			number    6		include "$(ZELDA_ROOT)/data/ydan_objects.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gnd" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/Gnd.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_am" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/Am.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_dekubaba" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/Dekubaba.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_oA3" 		flags   OBJECT 			number  	 	6		include "$(ZELDA_ROOT)/data/OA3.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_oA4" 		flags   OBJECT 			number  	 	6		include "$(ZELDA_ROOT)/data/OA4.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_oA5" 		flags   OBJECT 			number  	 	6		include "$(ZELDA_ROOT)/data/OA5.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_oA6" 		flags   OBJECT 			number  	 	6		include "$(ZELDA_ROOT)/data/OA6.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_oA7" 		flags   OBJECT 			number  	 	6		include "$(ZELDA_ROOT)/data/OA7.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_jj" 		flags   OBJECT 			number  	 	6		include "$(ZELDA_ROOT)/data/Jj.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_oA8" 		flags   OBJECT 			number  	 	6		include "$(ZELDA_ROOT)/data/OA8.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_oA9" 		flags   OBJECT 			number  	 	6		include "$(ZELDA_ROOT)/data/OA9.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_oB2" 		flags   OBJECT 			number  	 	6		include "$(ZELDA_ROOT)/data/OB2.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_oB3" 		flags   OBJECT 			number  	 	6		include "$(ZELDA_ROOT)/data/OB3.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_oB4" 		flags   OBJECT 			number  	 	6		include "$(ZELDA_ROOT)/data/OB4.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_horse_zelda" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/Horse_Zelda.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_opening_demo1" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/Opening_Demo1.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_warp1" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/Warp1.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_b_heart" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/B_heart.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_dekunuts" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/Dekunuts.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_oE3" 		flags   OBJECT 			number  	 	6		include "$(ZELDA_ROOT)/data/OE3.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_oE4" 		flags   OBJECT 			number  	 	6		include "$(ZELDA_ROOT)/data/OE4.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_menkuri_objects" 		flags   OBJECT 			number    6		include "$(ZELDA_ROOT)/data/menkuri_objects.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_oE5" 		flags   OBJECT 			number  	 	6		include "$(ZELDA_ROOT)/data/OE5.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_oE6" 		flags   OBJECT 			number  	 	6		include "$(ZELDA_ROOT)/data/OE6.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_oE7" 		flags   OBJECT 			number  	 	6		include "$(ZELDA_ROOT)/data/OE7.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_oE8" 		flags   OBJECT 			number  	 	6		include "$(ZELDA_ROOT)/data/OE8.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_oE9" 		flags   OBJECT 			number  	 	6		include "$(ZELDA_ROOT)/data/OE9.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_oE10" 		flags   OBJECT 			number  	 	6		include "$(ZELDA_ROOT)/data/OE10.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_oE11" 		flags   OBJECT 			number  	 	6		include "$(ZELDA_ROOT)/data/OE11.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_oE12" 		flags   OBJECT 			number  	 	6		include "$(ZELDA_ROOT)/data/OE12.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_vali" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/Vali.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_oA10" 		flags   OBJECT 			number  	 	6		include "$(ZELDA_ROOT)/data/OA10.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_oA11" 		flags   OBJECT 			number  	 	6		include "$(ZELDA_ROOT)/data/OA11.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_mizu_objects" 		flags   OBJECT 			number    6		include "$(ZELDA_ROOT)/data/mizu_objects.o" 		romalign 0x1000		endseg 



beginseg 				name    "object_fhg" 		flags   OBJECT 			number             6		include "$(ZELDA_ROOT)/data/FantomHG.o" 		romalign 0x1000		endseg 

beginseg 				name    "object_ossan" 		flags   OBJECT 			number  	 	6		include "$(ZELDA_ROOT)/data/OB1.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_mori_hineri1" 		flags   OBJECT 			number    6		include "$(ZELDA_ROOT)/data/mori_hineri1.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_Bb" 		flags   OBJECT 			number    		6		include "$(ZELDA_ROOT)/data/Bb.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_toki_objects" 		flags   OBJECT 			number    6		include "$(ZELDA_ROOT)/data/toki_objects.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_yukabyun" 		flags   OBJECT 			number    	6		include "$(ZELDA_ROOT)/data/Yukabyun.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_zl2" 		flags   OBJECT 			number    		6		include "$(ZELDA_ROOT)/data/Zl2.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_mjin" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/Mjin.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_mjin_flash" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/Flash_mjin.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_mjin_dark" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/Dark_mjin.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_mjin_flame" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/Flame_mjin.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_mjin_ice" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/Ice_mjin.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_mjin_soul" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/Soul_mjin.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_mjin_wind" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/Wind_mjin.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_mjin_oka" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/Oka_mjin.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_haka_objects" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/haka_objects.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_spot06_objects" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/spot06_objects.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_ice_objects" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/ice_objects.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_relay_objects" 		flags   OBJECT 			number    6		include "$(ZELDA_ROOT)/data/relay_objects.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_mori_hineri1a" 		flags   OBJECT 			number   6		include "$(ZELDA_ROOT)/data/mori_hineri1a.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_mori_hineri2" 		flags   OBJECT 			number    6		include "$(ZELDA_ROOT)/data/mori_hineri2.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_mori_hineri2a" 		flags   OBJECT 			number   6		include "$(ZELDA_ROOT)/data/mori_hineri2a.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_mori_objects" 		flags   OBJECT 			number    6		include "$(ZELDA_ROOT)/data/mori_objects.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_mori_tex" 		flags   OBJECT 			number  	8		include 	 "$(ZELDA_ROOT)/data/mori_tex.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_spot08_obj" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/spot08_obj.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_warp2" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/Warp2.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_hata" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/Hata.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_bird" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/Bird.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_wood02" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/Wood02.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_lightbox" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/Lightbox.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_pu_box" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/Pu_box.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_trap" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/Trap.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_vase" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/Vase.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_im" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/Im.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_ta" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/Ta.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_tk" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/Tk.o" 		romalign 0x1000		endseg 



beginseg 				name    "object_xc" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/Xc.o" 		romalign 0x1000		endseg 

beginseg 				name    "object_vm" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/Vm.o" 		romalign 0x1000		endseg 



beginseg 				name    "object_bv" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/Bv.o" 		romalign 0x1000		endseg 

beginseg 				name    "object_hakach_objects" 		flags   OBJECT 			number  6		include "$(ZELDA_ROOT)/data/hakach_objects.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_efc_crystal_light" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/efc_crystal_light.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_efc_fire_ball" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/efc_fire_ball.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_efc_flash" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/efc_flash.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_efc_lgt_shower" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/efc_lgt_shower.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_efc_star_field" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/efc_star_field.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_god_lgt" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/god_lgt.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_light_ring" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/light_ring.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_triforce_spot" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/triforce_spot.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_medal" 		flags   OBJECT 			number  	6		include  "$(ZELDA_ROOT)/data/medal.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_bdan_objects" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/bdan_objects.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_sd" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/Sd.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_rd" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/Rd.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_po_sisters" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/Po_Sisters.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_heavy_object" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/Heavy_object.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gndd" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/Gndd.o" 		romalign 0x1000		endseg 



beginseg 				name    "object_fd" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/fd.o" 		romalign 0x1000		endseg 





beginseg 				name    "object_du" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/du.o" 		romalign 0x1000		endseg 


beginseg 				name    "object_fw" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/fw.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_horse_link_child" 		flags   OBJECT 			number  6		include "$(ZELDA_ROOT)/data/hlc.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_spot02_objects" 		flags   OBJECT 			number  6		include "$(ZELDA_ROOT)/data/spot02_objects.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_haka" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/Haka.o" 		romalign 0x1000		endseg 

beginseg 				name    "object_ru1" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/ru1.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_syokudai" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/syokudai.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_fd2" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/fd2.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_dh" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/Dh.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_rl" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/Rl.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_efc_tw" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/efc_tw.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_demo_tre_lgt" 		flags   OBJECT 			number    6		include "$(ZELDA_ROOT)/data/demo_tre_lgt.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gi_key" 		flags   OBJECT 			number          6		include "$(ZELDA_ROOT)/data/gi_key.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_mir_ray" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/mir_ray.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_brob" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/Brob.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gi_jewel" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/gi_jewel.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_spot09_obj" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/spot09_obj.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_spot18_obj" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/spot18_obj.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_bdoor" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/bdoor.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_spot17_obj" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/spot17_obj.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_shop_dungen" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/shop_dungen.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_nb" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/nb.o" 		romalign 0x1000		endseg 



beginseg 				name    "object_mo" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/mo.o" 		romalign 0x1000		endseg 

beginseg 				name    "object_sb" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/sb.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gi_melody" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/gi_melody.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gi_heart" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/gi_heart.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gi_compass" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/gi_compass.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gi_bosskey" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/gi_bosskey.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gi_medal" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/gi_medal.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gi_nuts" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/gi_nuts.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_sa" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/sa.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gi_hearts" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/gi_hearts.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gi_arrowcase" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/gi_arrowcase.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gi_bombpouch" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/gi_bombpouch.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_in" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/In.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_tr" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/Tr.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_spot16_obj" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/spot16_obj.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_oE1s" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/oE1s.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_oE4s" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/oE4s.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_os_anime" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/os_anime.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gi_bottle" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/gi_bottle.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gi_stick" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/gi_stick.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gi_map" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/gi_map.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_oF1d_map" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/oF1d_map.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_ru2" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/ru2.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gi_shield_1" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/gi_shield_1.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_dekujr" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/dekujr.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gi_magicpot" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/gi_magicpot.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gi_bomb_1" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/gi_bomb_1.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_oF1s" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/oF1s.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_ma2" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/Ma2.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gi_purse" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/gi_purse.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_hni" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/Hni.o" 		romalign 0x1000		endseg  



beginseg 				name    "object_tw" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/tw.o" 		romalign 0x1000		endseg 

beginseg 				name    "object_rr" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/rr.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_bxa" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/bxa.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_anubice" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/Av.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gi_gerudo" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/gi_gerudo.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gi_arrow" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/gi_arrow.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gi_bomb_2" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/gi_bomb_2.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gi_egg" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/gi_egg.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gi_scale" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/gi_scale.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gi_shield_2" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/gi_shield_2.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gi_hookshot" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/gi_hookshot.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gi_ocarina" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/gi_ocarina.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gi_milk" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/gi_milk.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_ma1" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/Ma1.o" 		romalign 0x1000		endseg 



beginseg 				name    "object_ganon" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/B_ganon.o" 		romalign 0x1000		endseg 




beginseg 				name    "object_sst" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/Sst.o" 		romalign 0x1000		endseg 

beginseg 				name    "object_go2" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/Go2.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_ny" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/Ny.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_fr" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/Fr.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gi_pachinko" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/gi_pachinko.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gi_boomerang" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/gi_boomerang.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gi_bow" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/gi_bow.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gi_glasses" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/gi_glasses.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gi_liquid" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/gi_liquid.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_ani" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/ani.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_demo_6k" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/D6k.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gi_shield_3" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/gi_shield_3.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gi_letter" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/gi_letter.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_spot15_obj" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/spot15_obj.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_jya_obj" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/jya_obj.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gi_clothes" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/gi_clothes.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gi_bean" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/gi_bean.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gi_fish" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/gi_fish.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gi_saw" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/gi_saw.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gi_hammer" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/gi_hammer.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gi_grass" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/gi_grass.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gi_longsword" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/gi_longsword.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_spot01_objects" 		flags   OBJECT 			number    6		include "$(ZELDA_ROOT)/data/spot01_objects.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gate" 		flags   OBJECT 			number   		6		include "$(ZELDA_ROOT)/data/Gate.o" 		romalign 0x1000		endseg 

beginseg 				name    "object_md" 		flags   OBJECT 			number   		6		include "$(ZELDA_ROOT)/data/Md.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_km1" 		flags   OBJECT 			number   		6		include "$(ZELDA_ROOT)/data/Km1.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_kw1" 		flags   OBJECT 			number   		6		include "$(ZELDA_ROOT)/data/Kw1.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_zo" 		flags   OBJECT 			number   		6		include "$(ZELDA_ROOT)/data/Zo.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_kz" 		flags   OBJECT 			number   		6		include "$(ZELDA_ROOT)/data/Kz.o" 		romalign 0x1000		endseg 

beginseg 				name    "object_umajump" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/Umajump.o" 		romalign 0x1000		endseg 

beginseg 				name    "object_masterkokiri" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/masterkokiri.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_masterkokirihead" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/masterkokirihead.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_mastergolon" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/mastergolon.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_masterzoora" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/masterzoora.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_aob" 		flags   OBJECT 			number   		6		include "$(ZELDA_ROOT)/data/Aob.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_ik" 		flags   OBJECT 			number   		6		include "$(ZELDA_ROOT)/data/Ik.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_ahg" 		flags   OBJECT 			number   		6		include "$(ZELDA_ROOT)/data/Ahg.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_cne" 		flags   OBJECT 			number   		6		include "$(ZELDA_ROOT)/data/Cne.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gi_niwatori" 		flags   OBJECT 			number   	6		include "$(ZELDA_ROOT)/data/gi_niwatori.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_skj" 		flags   OBJECT 			number   		6		include "$(ZELDA_ROOT)/data/Skj.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gi_bottle_letter" 		flags   OBJECT 			number   	6		include "$(ZELDA_ROOT)/data/gi_bottle_letter.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_bji" 		flags   OBJECT 			number   	6		include "$(ZELDA_ROOT)/data/Bji.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_bba" 		flags   OBJECT 			number   	6		include "$(ZELDA_ROOT)/data/Bba.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gi_ocarina_0" 		flags   OBJECT 			number   	6		include "$(ZELDA_ROOT)/data/gi_ocarina_0.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_ds" 		flags   OBJECT 			number   	6		include "$(ZELDA_ROOT)/data/Ds.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_ane" 		flags   OBJECT 			number   	6		include "$(ZELDA_ROOT)/data/Ane.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_boj" 		flags   OBJECT 			number   	6		include "$(ZELDA_ROOT)/data/Boj.o" 		romalign 0x1000		endseg 

beginseg 				name    "object_spot03_object" 		flags   OBJECT 			number    6		include "$(ZELDA_ROOT)/data/spot03_object.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_spot07_object" 		flags   OBJECT 			number    6		include "$(ZELDA_ROOT)/data/spot07_object.o" 		romalign 0x1000		endseg 

beginseg 				name    "object_fz" 		flags   OBJECT 			number   	6		include "$(ZELDA_ROOT)/data/Fz.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_bob" 		flags   OBJECT 			number   	6		include "$(ZELDA_ROOT)/data/Bob.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_ge1" 		flags   OBJECT 			number   	6		include "$(ZELDA_ROOT)/data/Ge1.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_yabusame_point" 		flags   OBJECT 			number    6		include "$(ZELDA_ROOT)/data/yabusame_point.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gi_boots_2" 		flags   OBJECT 			number   	6		include "$(ZELDA_ROOT)/data/gi_boots_2.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gi_seed" 		flags   OBJECT 			number   	6		include "$(ZELDA_ROOT)/data/gi_seed.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gnd_magic" 		flags   OBJECT 			number   	6		include "$(ZELDA_ROOT)/data/gnd_magic.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_d_elevator" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/d_elevator.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_d_hsblock" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/d_hsblock.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_d_lift" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/d_lift.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_mamenoki" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/mamenoki.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_goroiwa" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/goroiwa.o" 		romalign 0x1000		endseg 



beginseg 				name    "object_toryo" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/toryo.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_daiku" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/daiku.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_nwc" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/nwc.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_blkobj" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/blkobj.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gm" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/gm.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_ms" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/ms.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_hs" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/hs.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_ingate" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/Ingate.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_lightswitch" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/lightswitch.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_kusa" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/kusa.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_tsubo" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/tsubo.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gi_gloves" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/gi_gloves.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gi_coin" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/gi_coin.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_kanban" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/kanban.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gjyo_objects" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/Gjyo_objects.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_owl" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/Owl.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_mk" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/Mk.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_fu" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/Fu.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gi_ki_tan_mask" 		flags   OBJECT 			number  6		include "$(ZELDA_ROOT)/data/gi_ki_tan_mask.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gi_redead_mask" 		flags   OBJECT 			number  6		include "$(ZELDA_ROOT)/data/gi_redead_mask.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gi_skj_mask" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/gi_skj_mask.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gi_rabit_mask" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/gi_rabit_mask.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gi_truth_mask" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/gi_truth_mask.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_ganon_objects" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/ganon_objects.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_siofuki" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/siofuki.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_stream" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/stream.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_mm" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/mm.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_fa" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/fa.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_os" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/os.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gi_eye_lotion" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/gi_eye_lotion.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gi_powder" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/gi_powder.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gi_mushroom" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/gi_mushroom.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gi_ticketstone" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/gi_ticketstone.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gi_brokensword" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/gi_brokensword.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_js" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/Js.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_cs" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/cs.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gi_prescription" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/gi_prescription.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gi_bracelet" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/gi_bracelet.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gi_soldout" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/gi_soldout.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gi_frog" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/gi_frog.o" 		romalign 0x1000		endseg 



beginseg 				name    "object_mag" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/mag.o" 		romalign 0x1000		endseg 

beginseg 				name    "object_door_gerudo" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/door_gerudo.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gt" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/gt.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_efc_erupc" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/efc_erupc.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_zl2_anime1" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/Zl2_Anime1.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_zl2_anime2" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/Zl2_Anime2.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gi_golonmask" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/gi_golonmask.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gi_zoramask" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/gi_zoramask.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gi_gerudomask" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/gi_gerudomask.o" 		romalign 0x1000		endseg 



beginseg 				name    "object_ganon2" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/B_ganon2.o" 		romalign 0x1000		endseg 

beginseg 				name    "object_ka" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/Ka.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_ts" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/Ts.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_zg" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/Zg.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gi_hoverboots" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/gi_hoverboots.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gi_m_arrow" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/gi_m_arrow.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_ds2" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/Ds2.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_ec" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/Ec.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_fish" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/Fish.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gi_sutaru" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/gi_sutaru.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gi_goddess" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/gi_goddess.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_ssh" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/ssh.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_bigokuta" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/Ocd.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_bg" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/Bg.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_spot05_objects" 		flags   OBJECT 			number    6		include "$(ZELDA_ROOT)/data/spot05_objects.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_spot12_obj" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/spot12_obj.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_bombiwa" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/bombiwa.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_hintnuts" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/Hintnuts.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_rs" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/Rs.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_spot00_break" 		flags   OBJECT 			number    6		include "$(ZELDA_ROOT)/data/spot00_break.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gla" 		flags   OBJECT 			number    6		include "$(ZELDA_ROOT)/data/Gla.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_shopnuts" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/Shopnuts.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_geldb" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/Gelb.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gr" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/Gr.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_dog" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/Dog.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_jya_iron" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/jya_iron.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_jya_door" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/jya_door.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_spot01_objects2" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/spot01_objects2.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_spot11_obj" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/spot11_obj.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_kibako2" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/kibako2.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_dns" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/Dns.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_dnk" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/Dnk.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gi_fire" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/gi_fire.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gi_insect" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/gi_insect.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gi_butterfly" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/gi_butterfly.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gi_ghost" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/gi_ghost.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gi_soul" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/gi_soul.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_bowl" 		flags   OBJECT 			number  			6		include "$(ZELDA_ROOT)/data/Bowl.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_po_field" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/Po_Field.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_demo_kekkai" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/Demo_Kekkai.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_efc_doughnut" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/Efc_Doughnut.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gi_dekupouch" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/gi_dekupouch.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_ganon_anime1" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/Ganon_Anime1.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_ganon_anime2" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/Ganon_Anime2.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_ganon_anime3" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/Ganon_Anime3.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gi_rupy" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/gi_rupy.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_spot01_matoya" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/spot01_matoya.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_spot01_matoyab" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/spot01_matoyab.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_po_composer" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/Po_Composer.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_mu" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/Mu.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_wf" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/Wf.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_skb" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/Skb.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gj" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/gj.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_geff" 		flags   OBJECT 			number  		6		include "$(ZELDA_ROOT)/data/geff.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_haka_door" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/haka_door.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gs" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/gs.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_ps" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/ps.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_bwall" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/Bwall.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_crow" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/Crow.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_cow" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/Cow.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_cob" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/Cob.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_gi_sword_1" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/gi_sword_1.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_door_killer" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/killer_door.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_ouke_haka" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/ouke_haka.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_timeblock" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/timeblock.o" 		romalign 0x1000		endseg 
beginseg 				name    "object_zl4" 		flags   OBJECT 			number   		6		include "$(ZELDA_ROOT)/data/Zl4.o" 		romalign 0x1000		endseg 

# 1891 "../spec.segment"

beginseg 				name    "g_pn_01" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/G_pn_01.o" 		romalign 0x1000		endseg 
beginseg 				name    "g_pn_02" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/G_pn_02.o" 		romalign 0x1000		endseg 
beginseg 				name    "g_pn_03" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/G_pn_03.o" 		romalign 0x1000		endseg 
beginseg 				name    "g_pn_04" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/G_pn_04.o" 		romalign 0x1000		endseg 
beginseg 				name    "g_pn_05" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/G_pn_05.o" 		romalign 0x1000		endseg 
beginseg 				name    "g_pn_06" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/G_pn_06.o" 		romalign 0x1000		endseg 
beginseg 				name    "g_pn_07" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/G_pn_07.o" 		romalign 0x1000		endseg 
beginseg 				name    "g_pn_08" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/G_pn_08.o" 		romalign 0x1000		endseg 
beginseg 				name    "g_pn_09" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/G_pn_09.o" 		romalign 0x1000		endseg 
beginseg 				name    "g_pn_10" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/G_pn_10.o" 		romalign 0x1000		endseg 
beginseg 				name    "g_pn_11" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/G_pn_11.o" 		romalign 0x1000		endseg 
beginseg 				name    "g_pn_12" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/G_pn_12.o" 		romalign 0x1000		endseg 
beginseg 				name    "g_pn_13" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/G_pn_13.o" 		romalign 0x1000		endseg 
beginseg 				name    "g_pn_14" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/G_pn_14.o" 		romalign 0x1000		endseg 
beginseg 				name    "g_pn_15" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/G_pn_15.o" 		romalign 0x1000		endseg 
beginseg 				name    "g_pn_16" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/G_pn_16.o" 		romalign 0x1000		endseg 
beginseg 				name    "g_pn_17" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/G_pn_17.o" 		romalign 0x1000		endseg 
beginseg 				name    "g_pn_18" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/G_pn_18.o" 		romalign 0x1000		endseg 
beginseg 				name    "g_pn_19" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/G_pn_19.o" 		romalign 0x1000		endseg 
beginseg 				name    "g_pn_20" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/G_pn_20.o" 		romalign 0x1000		endseg 
beginseg 				name    "g_pn_21" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/G_pn_21.o" 		romalign 0x1000		endseg 
beginseg 				name    "g_pn_22" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/G_pn_22.o" 		romalign 0x1000		endseg 
beginseg 				name    "g_pn_23" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/G_pn_23.o" 		romalign 0x1000		endseg 
beginseg 				name    "g_pn_24" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/G_pn_24.o" 		romalign 0x1000		endseg 
beginseg 				name    "g_pn_25" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/G_pn_25.o" 		romalign 0x1000		endseg 
beginseg 				name    "g_pn_26" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/G_pn_26.o" 		romalign 0x1000		endseg 
beginseg 				name    "g_pn_27" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/G_pn_27.o" 		romalign 0x1000		endseg 
beginseg 				name    "g_pn_28" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/G_pn_28.o" 		romalign 0x1000		endseg 
beginseg 				name    "g_pn_29" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/G_pn_29.o" 		romalign 0x1000		endseg 
beginseg 				name    "g_pn_30" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/G_pn_30.o" 		romalign 0x1000		endseg 
beginseg 				name    "g_pn_31" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/G_pn_31.o" 		romalign 0x1000		endseg 
beginseg 				name    "g_pn_32" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/G_pn_32.o" 		romalign 0x1000		endseg 
beginseg 				name    "g_pn_33" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/G_pn_33.o" 		romalign 0x1000		endseg 
beginseg 				name    "g_pn_34" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/G_pn_34.o" 		romalign 0x1000		endseg 
beginseg 				name    "g_pn_35" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/G_pn_35.o" 		romalign 0x1000		endseg 
beginseg 				name    "g_pn_36" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/G_pn_36.o" 		romalign 0x1000		endseg 
beginseg 				name    "g_pn_37" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/G_pn_37.o" 		romalign 0x1000		endseg 
beginseg 				name    "g_pn_38" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/G_pn_38.o" 		romalign 0x1000		endseg 
beginseg 				name    "g_pn_39" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/G_pn_39.o" 		romalign 0x1000		endseg 
beginseg 				name    "g_pn_40" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/G_pn_40.o" 		romalign 0x1000		endseg 
beginseg 				name    "g_pn_41" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/G_pn_41.o" 		romalign 0x1000		endseg 
beginseg 				name    "g_pn_42" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/G_pn_42.o" 		romalign 0x1000		endseg 
beginseg 				name    "g_pn_43" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/G_pn_43.o" 		romalign 0x1000		endseg 
beginseg 				name    "g_pn_44" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/G_pn_44.o" 		romalign 0x1000		endseg 
beginseg 				name    "g_pn_45" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/G_pn_45.o" 		romalign 0x1000		endseg 
beginseg 				name    "g_pn_46" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/G_pn_46.o" 		romalign 0x1000		endseg 
beginseg 				name    "g_pn_47" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/G_pn_47.o" 		romalign 0x1000		endseg 
beginseg 				name    "g_pn_48" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/G_pn_48.o" 		romalign 0x1000		endseg 
beginseg 				name    "g_pn_49" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/G_pn_49.o" 		romalign 0x1000		endseg 
beginseg 				name    "g_pn_50" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/G_pn_50.o" 		romalign 0x1000		endseg 
beginseg 				name    "g_pn_51" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/G_pn_51.o" 		romalign 0x1000		endseg 
beginseg 				name    "g_pn_52" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/G_pn_52.o" 		romalign 0x1000		endseg 
beginseg 				name    "g_pn_53" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/G_pn_53.o" 		romalign 0x1000		endseg 
beginseg 				name    "g_pn_54" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/G_pn_54.o" 		romalign 0x1000		endseg 
beginseg 				name    "g_pn_55" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/G_pn_55.o" 		romalign 0x1000		endseg 
beginseg 				name    "g_pn_56" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/G_pn_56.o" 		romalign 0x1000		endseg 
beginseg 				name    "g_pn_57" 		flags   OBJECT 			number  	6		include "$(ZELDA_ROOT)/data/G_pn_57.o" 		romalign 0x1000		endseg 

 


 
beginseg 				name    "z_select_static" 		flags   OBJECT 			number   		1		include  	"$(ZELDA_ROOT)/data/shape/course_mapx1/course_map_s.o" 		romalign 0x1000		endseg 

 


beginseg 				name    "nintendo_rogo_static" 		flags   OBJECT 			number   	1		include  	 "$(ZELDA_ROOT)/data/nintendo_rogo.o" 		romalign 0x1000		endseg 

 





beginseg 				name    "title_static" 		flags   OBJECT 			number   	1		include  		 "$(ZELDA_ROOT)/data/title.o" 		romalign 0x1000		endseg 







 


beginseg 				name    "parameter_static" 		flags   OBJECT 			number   		2		include  	 "$(ZELDA_ROOT)/data/parameter.o" 		romalign 0x1000		endseg 

 


 
beginseg 				name    "vr_fine0_static" 		flags   OBJECT 			number   		7		include  	 "$(ZELDA_ROOT)/data/vr_fine0_div8_idx.o" 		romalign 0x1000		endseg 
beginseg 				name    "vr_fine0_pal_static" 		flags   OBJECT 			number   		9		include 	 "$(ZELDA_ROOT)/data/vr_fine0_pal.o" 		romalign 0x1000		endseg 
 
beginseg 				name    "vr_fine1_static" 		flags   OBJECT 			number   		7		include  	 "$(ZELDA_ROOT)/data/vr_fine1_div8_idx.o" 		romalign 0x1000		endseg 
beginseg 				name    "vr_fine1_pal_static" 		flags   OBJECT 			number   		9		include 	 "$(ZELDA_ROOT)/data/vr_fine1_pal.o" 		romalign 0x1000		endseg 
 
beginseg 				name    "vr_fine2_static" 		flags   OBJECT 			number   		8		include  	 "$(ZELDA_ROOT)/data/vr_fine2_div8_idx.o" 		romalign 0x1000		endseg 
beginseg 				name    "vr_fine2_pal_static" 		flags   OBJECT 			number   		9		include 	 "$(ZELDA_ROOT)/data/vr_fine2_pal.o" 		romalign 0x1000		endseg 
 
beginseg 				name    "vr_fine3_static" 		flags   OBJECT 			number   		7		include  	 "$(ZELDA_ROOT)/data/vr_fine3_div8_idx.o" 		romalign 0x1000		endseg 
beginseg 				name    "vr_fine3_pal_static" 		flags   OBJECT 			number   		9		include 	 "$(ZELDA_ROOT)/data/vr_fine3_pal.o" 		romalign 0x1000		endseg 
 
beginseg 				name    "vr_cloud0_static" 		flags   OBJECT 			number   		7		include  	 "$(ZELDA_ROOT)/data/vr_cloud0_div8_idx.o" 		romalign 0x1000		endseg 
beginseg 				name    "vr_cloud0_pal_static" 		flags   OBJECT 			number   	9		include 	 "$(ZELDA_ROOT)/data/vr_cloud0_pal.o" 		romalign 0x1000		endseg 
 
beginseg 				name    "vr_cloud1_static" 		flags   OBJECT 			number   		8		include  	 "$(ZELDA_ROOT)/data/vr_cloud1_div8_idx.o" 		romalign 0x1000		endseg 
beginseg 				name    "vr_cloud1_pal_static" 		flags   OBJECT 			number   	9		include 	 "$(ZELDA_ROOT)/data/vr_cloud1_pal.o" 		romalign 0x1000		endseg 
 
beginseg 				name    "vr_cloud2_static" 		flags   OBJECT 			number   		7		include  	 "$(ZELDA_ROOT)/data/vr_cloud2_div8_idx.o" 		romalign 0x1000		endseg 
beginseg 				name    "vr_cloud2_pal_static" 		flags   OBJECT 			number   	9		include 	 "$(ZELDA_ROOT)/data/vr_cloud2_pal.o" 		romalign 0x1000		endseg 
 
beginseg 				name    "vr_cloud3_static" 		flags   OBJECT 			number   		8		include  	 "$(ZELDA_ROOT)/data/vr_cloud3_div8_idx.o" 		romalign 0x1000		endseg 
beginseg 				name    "vr_cloud3_pal_static" 		flags   OBJECT 			number   	9		include 	 "$(ZELDA_ROOT)/data/vr_cloud3_pal.o" 		romalign 0x1000		endseg 










 
beginseg 				name    "vr_holy0_static" 		flags   OBJECT 			number   		7		include  	 "$(ZELDA_ROOT)/data/vr_holy0_div8_idx.o" 		romalign 0x1000		endseg 
beginseg 				name    "vr_holy0_pal_static" 		flags   OBJECT 			number   		9		include 	 "$(ZELDA_ROOT)/data/vr_holy0_pal.o" 		romalign 0x1000		endseg 
beginseg 				name    "vr_holy1_static" 		flags   OBJECT 			number   		7		include  	 "$(ZELDA_ROOT)/data/vr_holy1_div8_idx.o" 		romalign 0x1000		endseg 
beginseg 				name    "vr_holy1_pal_static" 		flags   OBJECT 			number   		9		include 	 "$(ZELDA_ROOT)/data/vr_holy1_pal.o" 		romalign 0x1000		endseg 

 


 
beginseg 				name    "vr_MDVR_static" 		flags   OBJECT 			number   		7		include  	 "$(ZELDA_ROOT)/data/vr_MDVR_div8_idx.o" 		romalign 0x1000		endseg 
beginseg 				name    "vr_MDVR_pal_static" 		flags   OBJECT 			number   		9		include  	 "$(ZELDA_ROOT)/data/vr_MDVR_pal.o" 		romalign 0x1000		endseg 
 
beginseg 				name    "vr_MNVR_static" 		flags   OBJECT 			number   		7		include  	 "$(ZELDA_ROOT)/data/vr_MNVR_div8_idx.o" 		romalign 0x1000		endseg 
beginseg 				name    "vr_MNVR_pal_static" 		flags   OBJECT 			number   		9		include  	 "$(ZELDA_ROOT)/data/vr_MNVR_pal.o" 		romalign 0x1000		endseg 
 
beginseg 				name    "vr_RUVR_static" 		flags   OBJECT 			number   		7		include  	 "$(ZELDA_ROOT)/data/vr_RUVR_div8_idx.o" 		romalign 0x1000		endseg 
beginseg 				name    "vr_RUVR_pal_static" 		flags   OBJECT 			number   		9		include  	 "$(ZELDA_ROOT)/data/vr_RUVR_pal.o" 		romalign 0x1000		endseg 















 
beginseg 				name    "vr_LHVR_static" 		flags   OBJECT 			number   		7		include  	 "$(ZELDA_ROOT)/data/vr_LHVR_div8_idx.o" 		romalign 0x1000		endseg 
beginseg 				name    "vr_LHVR_pal_static" 		flags   OBJECT 			number   		9		include 	 "$(ZELDA_ROOT)/data/vr_LHVR_pal.o" 		romalign 0x1000		endseg 
 
beginseg 				name    "vr_KHVR_static" 		flags   OBJECT 			number   		7		include  	 "$(ZELDA_ROOT)/data/vr_KHVR_div8_idx.o" 		romalign 0x1000		endseg 
beginseg 				name    "vr_KHVR_pal_static" 		flags   OBJECT 			number   		9		include 	 "$(ZELDA_ROOT)/data/vr_KHVR_pal.o" 		romalign 0x1000		endseg 





 
beginseg 				name    "vr_K3VR_static" 		flags   OBJECT 			number   		7		include  	 "$(ZELDA_ROOT)/data/vr_K3VR_div8_idx.o" 		romalign 0x1000		endseg 
beginseg 				name    "vr_K3VR_pal_static" 		flags   OBJECT 			number   		9		include 	 "$(ZELDA_ROOT)/data/vr_K3VR_pal.o" 		romalign 0x1000		endseg 
 
beginseg 				name    "vr_K4VR_static" 		flags   OBJECT 			number   		7		include  	 "$(ZELDA_ROOT)/data/vr_K4VR_div8_idx.o" 		romalign 0x1000		endseg 
beginseg 				name    "vr_K4VR_pal_static" 		flags   OBJECT 			number   		9		include 	 "$(ZELDA_ROOT)/data/vr_K4VR_pal.o" 		romalign 0x1000		endseg 
 
beginseg 				name    "vr_K5VR_static" 		flags   OBJECT 			number   		7		include  	 "$(ZELDA_ROOT)/data/vr_K5VR_div8_idx.o" 		romalign 0x1000		endseg 
beginseg 				name    "vr_K5VR_pal_static" 		flags   OBJECT 			number   		9		include 	 "$(ZELDA_ROOT)/data/vr_K5VR_pal.o" 		romalign 0x1000		endseg 
 
beginseg 				name    "vr_SP1a_static" 		flags   OBJECT 			number   		7		include  	 "$(ZELDA_ROOT)/data/vr_SP1a_div8_idx.o" 		romalign 0x1000		endseg 
beginseg 				name    "vr_SP1a_pal_static" 		flags   OBJECT 			number   		9		include 	 "$(ZELDA_ROOT)/data/vr_SP1a_pal.o" 		romalign 0x1000		endseg 
 
beginseg 				name    "vr_MLVR_static" 		flags   OBJECT 			number   		7		include  	 "$(ZELDA_ROOT)/data/vr_MLVR_div8_idx.o" 		romalign 0x1000		endseg 
beginseg 				name    "vr_MLVR_pal_static" 		flags   OBJECT 			number   		9		include 	 "$(ZELDA_ROOT)/data/vr_MLVR_pal.o" 		romalign 0x1000		endseg 
 
beginseg 				name    "vr_KKRVR_static" 		flags   OBJECT 			number   		7		include  	 "$(ZELDA_ROOT)/data/vr_KKRVR_div8_idx.o" 		romalign 0x1000		endseg 
beginseg 				name    "vr_KKRVR_pal_static" 		flags   OBJECT 			number   		9		include 	 "$(ZELDA_ROOT)/data/vr_KKRVR_pal.o" 		romalign 0x1000		endseg 





 
beginseg 				name    "vr_KR3VR_static" 		flags   OBJECT 			number   		7		include  	 "$(ZELDA_ROOT)/data/vr_KR3VR_div8_idx.o" 		romalign 0x1000		endseg 
beginseg 				name    "vr_KR3VR_pal_static" 		flags   OBJECT 			number   		9		include 	 "$(ZELDA_ROOT)/data/vr_KR3VR_pal.o" 		romalign 0x1000		endseg 
 
beginseg 				name    "vr_IPVR_static" 		flags   OBJECT 			number   		7		include  	 "$(ZELDA_ROOT)/data/vr_IPVR_div8_idx.o" 		romalign 0x1000		endseg 
beginseg 				name    "vr_IPVR_pal_static" 		flags   OBJECT 			number   		9		include 	 "$(ZELDA_ROOT)/data/vr_IPVR_pal.o" 		romalign 0x1000		endseg 
 
beginseg 				name    "vr_KSVR_static" 		flags   OBJECT 			number   		7		include  	 "$(ZELDA_ROOT)/data/vr_KSVR_div8_idx.o" 		romalign 0x1000		endseg 
beginseg 				name    "vr_KSVR_pal_static" 		flags   OBJECT 			number   		9		include 	 "$(ZELDA_ROOT)/data/vr_KSVR_pal.o" 		romalign 0x1000		endseg 





 
beginseg 				name    "vr_GLVR_static" 		flags   OBJECT 			number   		7		include  	 "$(ZELDA_ROOT)/data/vr_GLVR_div8_idx.o" 		romalign 0x1000		endseg 
beginseg 				name    "vr_GLVR_pal_static" 		flags   OBJECT 			number   		9		include 	 "$(ZELDA_ROOT)/data/vr_GLVR_pal.o" 		romalign 0x1000		endseg 
 
beginseg 				name    "vr_ZRVR_static" 		flags   OBJECT 			number   		7		include  	 "$(ZELDA_ROOT)/data/vr_ZRVR_div8_idx.o" 		romalign 0x1000		endseg 
beginseg 				name    "vr_ZRVR_pal_static" 		flags   OBJECT 			number   		9		include 	 "$(ZELDA_ROOT)/data/vr_ZRVR_pal.o" 		romalign 0x1000		endseg 





 
beginseg 				name    "vr_DGVR_static" 		flags   OBJECT 			number   		7		include  	 "$(ZELDA_ROOT)/data/vr_DGVR_div8_idx.o" 		romalign 0x1000		endseg 
beginseg 				name    "vr_DGVR_pal_static" 		flags   OBJECT 			number   		9		include 	 "$(ZELDA_ROOT)/data/vr_DGVR_pal.o" 		romalign 0x1000		endseg 
 
beginseg 				name    "vr_ALVR_static" 		flags   OBJECT 			number   		7		include  	 "$(ZELDA_ROOT)/data/vr_ALVR_div8_idx.o" 		romalign 0x1000		endseg 
beginseg 				name    "vr_ALVR_pal_static" 		flags   OBJECT 			number   		9		include 	 "$(ZELDA_ROOT)/data/vr_ALVR_pal.o" 		romalign 0x1000		endseg 
 
beginseg 				name    "vr_NSVR_static" 		flags   OBJECT 			number   		7		include  	 "$(ZELDA_ROOT)/data/vr_NSVR_div8_idx.o" 		romalign 0x1000		endseg 
beginseg 				name    "vr_NSVR_pal_static" 		flags   OBJECT 			number   		9		include 	 "$(ZELDA_ROOT)/data/vr_NSVR_pal.o" 		romalign 0x1000		endseg 
 
beginseg 				name    "vr_LBVR_static" 		flags   OBJECT 			number   		7		include  	 "$(ZELDA_ROOT)/data/vr_LBVR_div8_idx.o" 		romalign 0x1000		endseg 
beginseg 				name    "vr_LBVR_pal_static" 		flags   OBJECT 			number   		9		include 	 "$(ZELDA_ROOT)/data/vr_LBVR_pal.o" 		romalign 0x1000		endseg 
 
beginseg 				name    "vr_TTVR_static" 		flags   OBJECT 			number   		7		include  	 "$(ZELDA_ROOT)/data/vr_TTVR_div8_idx.o" 		romalign 0x1000		endseg 
beginseg 				name    "vr_TTVR_pal_static" 		flags   OBJECT 			number   		9		include 	 "$(ZELDA_ROOT)/data/vr_TTVR_pal.o" 		romalign 0x1000		endseg 
 
beginseg 				name    "vr_FCVR_static" 		flags   OBJECT 			number   		7		include  	 "$(ZELDA_ROOT)/data/vr_FCVR_div8_idx.o" 		romalign 0x1000		endseg 
beginseg 				name    "vr_FCVR_pal_static" 		flags   OBJECT 			number   		9		include 	 "$(ZELDA_ROOT)/data/vr_FCVR_pal.o" 		romalign 0x1000		endseg 













 



beginseg 				name    "elf_message_field" 		flags   OBJECT 			number  	7		include  "$(ZELDA_ROOT)/data/EM_field.o" 		romalign 0x1000		endseg 
beginseg 				name    "elf_message_ydan" 		flags   OBJECT 			number  	7		include  "$(ZELDA_ROOT)/data/EM_ydan.o" 		romalign 0x1000		endseg 




beginseg 				name    "ydan_scene" 		flags   OBJECT 			number  		2		include  "$(ZELDA_ROOT)/data/Ydan_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "ydan_room_0" 		flags   OBJECT 			number  	 	3		include  	"$(ZELDA_ROOT)/data/Ydan_ROOM0.o" 		romalign 0x1000		endseg 
beginseg 				name    "ydan_room_1" 		flags   OBJECT 			number   		3		include  	"$(ZELDA_ROOT)/data/Ydan_ROOM1.o" 		romalign 0x1000		endseg 
beginseg 				name    "ydan_room_2" 		flags   OBJECT 			number   		3		include  	"$(ZELDA_ROOT)/data/Ydan_ROOM2.o" 		romalign 0x1000		endseg 
beginseg 				name    "ydan_room_3" 		flags   OBJECT 			number   		3		include  	"$(ZELDA_ROOT)/data/Ydan_ROOM3.o" 		romalign 0x1000		endseg 
beginseg 				name    "ydan_room_4" 		flags   OBJECT 			number   		3		include  	"$(ZELDA_ROOT)/data/Ydan_ROOM4.o" 		romalign 0x1000		endseg 
beginseg 				name    "ydan_room_5" 		flags   OBJECT 			number   		3		include  	"$(ZELDA_ROOT)/data/Ydan_ROOM5.o" 		romalign 0x1000		endseg 
beginseg 				name    "ydan_room_6" 		flags   OBJECT 			number   		3		include  	"$(ZELDA_ROOT)/data/Ydan_ROOM6.o" 		romalign 0x1000		endseg 
beginseg 				name    "ydan_room_7" 		flags   OBJECT 			number   		3		include  	"$(ZELDA_ROOT)/data/Ydan_ROOM7.o" 		romalign 0x1000		endseg 
beginseg 				name    "ydan_room_8" 		flags   OBJECT 			number   		3		include  	"$(ZELDA_ROOT)/data/Ydan_ROOM8.o" 		romalign 0x1000		endseg 
beginseg 				name    "ydan_room_9" 		flags   OBJECT 			number  		3		include  	"$(ZELDA_ROOT)/data/Ydan_ROOM9.o" 		romalign 0x1000		endseg 
beginseg 				name    "ydan_room_10" 		flags   OBJECT 			number  		3		include  	"$(ZELDA_ROOT)/data/Ydan_ROOM10.o" 		romalign 0x1000		endseg 
beginseg 				name    "ydan_room_11" 		flags   OBJECT 			number  		3		include  	"$(ZELDA_ROOT)/data/Ydan_ROOM11.o" 		romalign 0x1000		endseg 

beginseg 				name    "ddan_scene" 		flags   OBJECT 			number   	        2		include  "$(ZELDA_ROOT)/data/Ddan_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "ddan_room_0" 		flags   OBJECT 			number   		3		include  	"$(ZELDA_ROOT)/data/Ddan_ROOM0.o" 		romalign 0x1000		endseg 
beginseg 				name    "ddan_room_1" 		flags   OBJECT 			number   		3		include  	"$(ZELDA_ROOT)/data/Ddan_ROOM1.o" 		romalign 0x1000		endseg 
beginseg 				name    "ddan_room_2" 		flags   OBJECT 			number   		3		include  	"$(ZELDA_ROOT)/data/Ddan_ROOM2.o" 		romalign 0x1000		endseg 
beginseg 				name    "ddan_room_3" 		flags   OBJECT 			number   		3		include  	"$(ZELDA_ROOT)/data/Ddan_ROOM3.o" 		romalign 0x1000		endseg 
beginseg 				name    "ddan_room_4" 		flags   OBJECT 			number   		3		include  	"$(ZELDA_ROOT)/data/Ddan_ROOM4.o" 		romalign 0x1000		endseg 
beginseg 				name    "ddan_room_5" 		flags   OBJECT 			number   		3		include  	"$(ZELDA_ROOT)/data/Ddan_ROOM5.o" 		romalign 0x1000		endseg 
beginseg 				name    "ddan_room_6" 		flags   OBJECT 			number   		3		include  	"$(ZELDA_ROOT)/data/Ddan_ROOM6.o" 		romalign 0x1000		endseg 
beginseg 				name    "ddan_room_7" 		flags   OBJECT 			number   		3		include  	"$(ZELDA_ROOT)/data/Ddan_ROOM7.o" 		romalign 0x1000		endseg 
beginseg 				name    "ddan_room_8" 		flags   OBJECT 			number   		3		include  	"$(ZELDA_ROOT)/data/Ddan_ROOM8.o" 		romalign 0x1000		endseg 
beginseg 				name    "ddan_room_9" 		flags   OBJECT 			number   		3		include  	"$(ZELDA_ROOT)/data/Ddan_ROOM9.o" 		romalign 0x1000		endseg 
beginseg 				name    "ddan_room_10" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Ddan_ROOM10.o" 		romalign 0x1000		endseg 
beginseg 				name    "ddan_room_11" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Ddan_ROOM11.o" 		romalign 0x1000		endseg 
beginseg 				name    "ddan_room_12" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Ddan_ROOM12.o" 		romalign 0x1000		endseg 
beginseg 				name    "ddan_room_13" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Ddan_ROOM13.o" 		romalign 0x1000		endseg 
beginseg 				name    "ddan_room_14" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Ddan_ROOM14.o" 		romalign 0x1000		endseg 
beginseg 				name    "ddan_room_15" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Ddan_ROOM15.o" 		romalign 0x1000		endseg 
beginseg 				name    "ddan_room_16" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Ddan_ROOM16.o" 		romalign 0x1000		endseg 

beginseg 				name    "bdan_scene" 		flags   OBJECT 			number  	2		include  "$(ZELDA_ROOT)/data/Bdan_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "bdan_room_0" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Bdan_ROOM0.o" 		romalign 0x1000		endseg 
beginseg 				name    "bdan_room_1" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Bdan_ROOM1.o" 		romalign 0x1000		endseg 
beginseg 				name    "bdan_room_2" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Bdan_ROOM2.o" 		romalign 0x1000		endseg 
beginseg 				name    "bdan_room_3" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Bdan_ROOM3.o" 		romalign 0x1000		endseg 
beginseg 				name    "bdan_room_4" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Bdan_ROOM4.o" 		romalign 0x1000		endseg 
beginseg 				name    "bdan_room_5" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Bdan_ROOM5.o" 		romalign 0x1000		endseg 
beginseg 				name    "bdan_room_6" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Bdan_ROOM6.o" 		romalign 0x1000		endseg 
beginseg 				name    "bdan_room_7" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Bdan_ROOM7.o" 		romalign 0x1000		endseg 
beginseg 				name    "bdan_room_8" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Bdan_ROOM8.o" 		romalign 0x1000		endseg 
beginseg 				name    "bdan_room_9" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Bdan_ROOM9.o" 		romalign 0x1000		endseg 
beginseg 				name    "bdan_room_10" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Bdan_ROOM10.o" 		romalign 0x1000		endseg 
beginseg 				name    "bdan_room_11" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Bdan_ROOM11.o" 		romalign 0x1000		endseg 
beginseg 				name    "bdan_room_12" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Bdan_ROOM12.o" 		romalign 0x1000		endseg 
beginseg 				name    "bdan_room_13" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Bdan_ROOM13.o" 		romalign 0x1000		endseg 
beginseg 				name    "bdan_room_14" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Bdan_ROOM14.o" 		romalign 0x1000		endseg 
beginseg 				name    "bdan_room_15" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Bdan_ROOM15.o" 		romalign 0x1000		endseg 

beginseg 				name    "Bmori1_scene" 		flags   OBJECT 			number   	2		include  "$(ZELDA_ROOT)/data/Bmori1_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "Bmori1_room_0" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Bmori1_ROOM0.o" 		romalign 0x1000		endseg 
beginseg 				name    "Bmori1_room_1" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Bmori1_ROOM1.o" 		romalign 0x1000		endseg 
beginseg 				name    "Bmori1_room_2" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Bmori1_ROOM2.o" 		romalign 0x1000		endseg 
beginseg 				name    "Bmori1_room_3" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Bmori1_ROOM3.o" 		romalign 0x1000		endseg 
beginseg 				name    "Bmori1_room_4" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Bmori1_ROOM4.o" 		romalign 0x1000		endseg 
beginseg 				name    "Bmori1_room_5" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Bmori1_ROOM5.o" 		romalign 0x1000		endseg 
beginseg 				name    "Bmori1_room_6" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Bmori1_ROOM6.o" 		romalign 0x1000		endseg 
beginseg 				name    "Bmori1_room_7" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Bmori1_ROOM7.o" 		romalign 0x1000		endseg 
beginseg 				name    "Bmori1_room_8" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Bmori1_ROOM8.o" 		romalign 0x1000		endseg 
beginseg 				name    "Bmori1_room_9" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Bmori1_ROOM9.o" 		romalign 0x1000		endseg 
beginseg 				name    "Bmori1_room_10" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Bmori1_ROOM10.o" 		romalign 0x1000		endseg 
beginseg 				name    "Bmori1_room_11" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Bmori1_ROOM11.o" 		romalign 0x1000		endseg 
beginseg 				name    "Bmori1_room_12" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Bmori1_ROOM12.o" 		romalign 0x1000		endseg 
beginseg 				name    "Bmori1_room_13" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Bmori1_ROOM13.o" 		romalign 0x1000		endseg 
beginseg 				name    "Bmori1_room_14" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Bmori1_ROOM14.o" 		romalign 0x1000		endseg 
beginseg 				name    "Bmori1_room_15" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Bmori1_ROOM15.o" 		romalign 0x1000		endseg 
beginseg 				name    "Bmori1_room_16" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Bmori1_ROOM16.o" 		romalign 0x1000		endseg 
beginseg 				name    "Bmori1_room_17" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Bmori1_ROOM17.o" 		romalign 0x1000		endseg 
beginseg 				name    "Bmori1_room_18" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Bmori1_ROOM18.o" 		romalign 0x1000		endseg 
beginseg 				name    "Bmori1_room_19" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Bmori1_ROOM19.o" 		romalign 0x1000		endseg 
beginseg 				name    "Bmori1_room_20" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Bmori1_ROOM20.o" 		romalign 0x1000		endseg 
beginseg 				name    "Bmori1_room_21" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Bmori1_ROOM21.o" 		romalign 0x1000		endseg 
beginseg 				name    "Bmori1_room_22" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Bmori1_ROOM22.o" 		romalign 0x1000		endseg 

beginseg 				name    "HIDAN_scene" 		flags   OBJECT 			number   		2		include  "$(ZELDA_ROOT)/data/Hidan_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "HIDAN_room_0" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Hidan_ROOM0.o" 		romalign 0x1000		endseg 
beginseg 				name    "HIDAN_room_1" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Hidan_ROOM1.o" 		romalign 0x1000		endseg 
beginseg 				name    "HIDAN_room_2" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Hidan_ROOM2.o" 		romalign 0x1000		endseg 
beginseg 				name    "HIDAN_room_3" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Hidan_ROOM3.o" 		romalign 0x1000		endseg 
beginseg 				name    "HIDAN_room_4" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Hidan_ROOM4.o" 		romalign 0x1000		endseg 
beginseg 				name    "HIDAN_room_5" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Hidan_ROOM5.o" 		romalign 0x1000		endseg 
beginseg 				name    "HIDAN_room_6" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Hidan_ROOM6.o" 		romalign 0x1000		endseg 
beginseg 				name    "HIDAN_room_7" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Hidan_ROOM7.o" 		romalign 0x1000		endseg 
beginseg 				name    "HIDAN_room_8" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Hidan_ROOM8.o" 		romalign 0x1000		endseg 
beginseg 				name    "HIDAN_room_9" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Hidan_ROOM9.o" 		romalign 0x1000		endseg 
beginseg 				name    "HIDAN_room_10" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Hidan_ROOM10.o" 		romalign 0x1000		endseg 
beginseg 				name    "HIDAN_room_11" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Hidan_ROOM11.o" 		romalign 0x1000		endseg 
beginseg 				name    "HIDAN_room_12" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Hidan_ROOM12.o" 		romalign 0x1000		endseg 
beginseg 				name    "HIDAN_room_13" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Hidan_ROOM13.o" 		romalign 0x1000		endseg 
beginseg 				name    "HIDAN_room_14" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Hidan_ROOM14.o" 		romalign 0x1000		endseg 
beginseg 				name    "HIDAN_room_15" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Hidan_ROOM15.o" 		romalign 0x1000		endseg 
beginseg 				name    "HIDAN_room_16" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Hidan_ROOM16.o" 		romalign 0x1000		endseg 
beginseg 				name    "HIDAN_room_17" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Hidan_ROOM17.o" 		romalign 0x1000		endseg 
beginseg 				name    "HIDAN_room_18" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Hidan_ROOM18.o" 		romalign 0x1000		endseg 
beginseg 				name    "HIDAN_room_19" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Hidan_ROOM19.o" 		romalign 0x1000		endseg 
beginseg 				name    "HIDAN_room_20" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Hidan_ROOM20.o" 		romalign 0x1000		endseg 
beginseg 				name    "HIDAN_room_21" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Hidan_ROOM21.o" 		romalign 0x1000		endseg 
beginseg 				name    "HIDAN_room_22" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Hidan_ROOM22.o" 		romalign 0x1000		endseg 
beginseg 				name    "HIDAN_room_23" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Hidan_ROOM23.o" 		romalign 0x1000		endseg 
beginseg 				name    "HIDAN_room_24" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Hidan_ROOM24.o" 		romalign 0x1000		endseg 
beginseg 				name    "HIDAN_room_25" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Hidan_ROOM25.o" 		romalign 0x1000		endseg 
beginseg 				name    "HIDAN_room_26" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Hidan_ROOM26.o" 		romalign 0x1000		endseg 

beginseg 				name    "MIZUsin_scene" 		flags   OBJECT 			number  	2		include  "$(ZELDA_ROOT)/data/Mizusin_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "MIZUsin_room_0" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Mizusin_ROOM0.o" 		romalign 0x1000		endseg 
beginseg 				name    "MIZUsin_room_1" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Mizusin_ROOM1.o" 		romalign 0x1000		endseg 
beginseg 				name    "MIZUsin_room_2" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Mizusin_ROOM2.o" 		romalign 0x1000		endseg 
beginseg 				name    "MIZUsin_room_3" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Mizusin_ROOM3.o" 		romalign 0x1000		endseg 
beginseg 				name    "MIZUsin_room_4" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Mizusin_ROOM4.o" 		romalign 0x1000		endseg 
beginseg 				name    "MIZUsin_room_5" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Mizusin_ROOM5.o" 		romalign 0x1000		endseg 
beginseg 				name    "MIZUsin_room_6" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Mizusin_ROOM6.o" 		romalign 0x1000		endseg 
beginseg 				name    "MIZUsin_room_7" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Mizusin_ROOM7.o" 		romalign 0x1000		endseg 
beginseg 				name    "MIZUsin_room_8" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Mizusin_ROOM8.o" 		romalign 0x1000		endseg 
beginseg 				name    "MIZUsin_room_9" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Mizusin_ROOM9.o" 		romalign 0x1000		endseg 
beginseg 				name    "MIZUsin_room_10" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Mizusin_ROOM10.o" 		romalign 0x1000		endseg 
beginseg 				name    "MIZUsin_room_11" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Mizusin_ROOM11.o" 		romalign 0x1000		endseg 
beginseg 				name    "MIZUsin_room_12" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Mizusin_ROOM12.o" 		romalign 0x1000		endseg 
beginseg 				name    "MIZUsin_room_13" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Mizusin_ROOM13.o" 		romalign 0x1000		endseg 
beginseg 				name    "MIZUsin_room_14" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Mizusin_ROOM14.o" 		romalign 0x1000		endseg 
beginseg 				name    "MIZUsin_room_15" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Mizusin_ROOM15.o" 		romalign 0x1000		endseg 
beginseg 				name    "MIZUsin_room_16" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Mizusin_ROOM16.o" 		romalign 0x1000		endseg 
beginseg 				name    "MIZUsin_room_17" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Mizusin_ROOM17.o" 		romalign 0x1000		endseg 
beginseg 				name    "MIZUsin_room_18" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Mizusin_ROOM18.o" 		romalign 0x1000		endseg 
beginseg 				name    "MIZUsin_room_19" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Mizusin_ROOM19.o" 		romalign 0x1000		endseg 
beginseg 				name    "MIZUsin_room_20" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Mizusin_ROOM20.o" 		romalign 0x1000		endseg 
beginseg 				name    "MIZUsin_room_21" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Mizusin_ROOM21.o" 		romalign 0x1000		endseg 
beginseg 				name    "MIZUsin_room_22" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Mizusin_ROOM22.o" 		romalign 0x1000		endseg 

beginseg 				name    "jyasinzou_scene" 		flags   OBJECT 			number  	2		include  "$(ZELDA_ROOT)/data/Jyasinzou_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "jyasinzou_room_0" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Jyasinzou_ROOM0.o" 		romalign 0x1000		endseg 
beginseg 				name    "jyasinzou_room_1" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Jyasinzou_ROOM1.o" 		romalign 0x1000		endseg 
beginseg 				name    "jyasinzou_room_2" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Jyasinzou_ROOM2.o" 		romalign 0x1000		endseg 
beginseg 				name    "jyasinzou_room_3" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Jyasinzou_ROOM3.o" 		romalign 0x1000		endseg 
beginseg 				name    "jyasinzou_room_4" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Jyasinzou_ROOM4.o" 		romalign 0x1000		endseg 
beginseg 				name    "jyasinzou_room_5" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Jyasinzou_ROOM5.o" 		romalign 0x1000		endseg 
beginseg 				name    "jyasinzou_room_6" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Jyasinzou_ROOM6.o" 		romalign 0x1000		endseg 
beginseg 				name    "jyasinzou_room_7" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Jyasinzou_ROOM7.o" 		romalign 0x1000		endseg 
beginseg 				name    "jyasinzou_room_8" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Jyasinzou_ROOM8.o" 		romalign 0x1000		endseg 
beginseg 				name    "jyasinzou_room_9" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Jyasinzou_ROOM9.o" 		romalign 0x1000		endseg 
beginseg 				name    "jyasinzou_room_10" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Jyasinzou_ROOM10.o" 		romalign 0x1000		endseg 
beginseg 				name    "jyasinzou_room_11" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Jyasinzou_ROOM11.o" 		romalign 0x1000		endseg 
beginseg 				name    "jyasinzou_room_12" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Jyasinzou_ROOM12.o" 		romalign 0x1000		endseg 
beginseg 				name    "jyasinzou_room_13" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Jyasinzou_ROOM13.o" 		romalign 0x1000		endseg 
beginseg 				name    "jyasinzou_room_14" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Jyasinzou_ROOM14.o" 		romalign 0x1000		endseg 
beginseg 				name    "jyasinzou_room_15" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Jyasinzou_ROOM15.o" 		romalign 0x1000		endseg 
beginseg 				name    "jyasinzou_room_16" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Jyasinzou_ROOM16.o" 		romalign 0x1000		endseg 
beginseg 				name    "jyasinzou_room_17" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Jyasinzou_ROOM17.o" 		romalign 0x1000		endseg 
beginseg 				name    "jyasinzou_room_18" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Jyasinzou_ROOM18.o" 		romalign 0x1000		endseg 
beginseg 				name    "jyasinzou_room_19" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Jyasinzou_ROOM19.o" 		romalign 0x1000		endseg 
beginseg 				name    "jyasinzou_room_20" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Jyasinzou_ROOM20.o" 		romalign 0x1000		endseg 
beginseg 				name    "jyasinzou_room_21" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Jyasinzou_ROOM21.o" 		romalign 0x1000		endseg 
beginseg 				name    "jyasinzou_room_22" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Jyasinzou_ROOM22.o" 		romalign 0x1000		endseg 
beginseg 				name    "jyasinzou_room_23" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Jyasinzou_ROOM23.o" 		romalign 0x1000		endseg 
beginseg 				name    "jyasinzou_room_24" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Jyasinzou_ROOM24.o" 		romalign 0x1000		endseg 
beginseg 				name    "jyasinzou_room_25" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Jyasinzou_ROOM25.o" 		romalign 0x1000		endseg 
beginseg 				name    "jyasinzou_room_26" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Jyasinzou_ROOM26.o" 		romalign 0x1000		endseg 
beginseg 				name    "jyasinzou_room_27" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Jyasinzou_ROOM27.o" 		romalign 0x1000		endseg 
beginseg 				name    "jyasinzou_room_28" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Jyasinzou_ROOM28.o" 		romalign 0x1000		endseg 

beginseg 				name    "HAKAdan_scene" 		flags   OBJECT 			number  	2		include  "$(ZELDA_ROOT)/data/Hakadan_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "HAKAdan_room_0" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Hakadan_ROOM0.o" 		romalign 0x1000		endseg 
beginseg 				name    "HAKAdan_room_1" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Hakadan_ROOM1.o" 		romalign 0x1000		endseg 
beginseg 				name    "HAKAdan_room_2" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Hakadan_ROOM2.o" 		romalign 0x1000		endseg 
beginseg 				name    "HAKAdan_room_3" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Hakadan_ROOM3.o" 		romalign 0x1000		endseg 
beginseg 				name    "HAKAdan_room_4" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Hakadan_ROOM4.o" 		romalign 0x1000		endseg 
beginseg 				name    "HAKAdan_room_5" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Hakadan_ROOM5.o" 		romalign 0x1000		endseg 
beginseg 				name    "HAKAdan_room_6" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Hakadan_ROOM6.o" 		romalign 0x1000		endseg 
beginseg 				name    "HAKAdan_room_7" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Hakadan_ROOM7.o" 		romalign 0x1000		endseg 
beginseg 				name    "HAKAdan_room_8" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Hakadan_ROOM8.o" 		romalign 0x1000		endseg 
beginseg 				name    "HAKAdan_room_9" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Hakadan_ROOM9.o" 		romalign 0x1000		endseg 
beginseg 				name    "HAKAdan_room_10" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Hakadan_ROOM10.o" 		romalign 0x1000		endseg 
beginseg 				name    "HAKAdan_room_11" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Hakadan_ROOM11.o" 		romalign 0x1000		endseg 
beginseg 				name    "HAKAdan_room_12" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Hakadan_ROOM12.o" 		romalign 0x1000		endseg 
beginseg 				name    "HAKAdan_room_13" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Hakadan_ROOM13.o" 		romalign 0x1000		endseg 
beginseg 				name    "HAKAdan_room_14" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Hakadan_ROOM14.o" 		romalign 0x1000		endseg 
beginseg 				name    "HAKAdan_room_15" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Hakadan_ROOM15.o" 		romalign 0x1000		endseg 
beginseg 				name    "HAKAdan_room_16" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Hakadan_ROOM16.o" 		romalign 0x1000		endseg 
beginseg 				name    "HAKAdan_room_17" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Hakadan_ROOM17.o" 		romalign 0x1000		endseg 
beginseg 				name    "HAKAdan_room_18" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Hakadan_ROOM18.o" 		romalign 0x1000		endseg 
beginseg 				name    "HAKAdan_room_19" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Hakadan_ROOM19.o" 		romalign 0x1000		endseg 
beginseg 				name    "HAKAdan_room_20" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Hakadan_ROOM20.o" 		romalign 0x1000		endseg 
beginseg 				name    "HAKAdan_room_21" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Hakadan_ROOM21.o" 		romalign 0x1000		endseg 
beginseg 				name    "HAKAdan_room_22" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Hakadan_ROOM22.o" 		romalign 0x1000		endseg 

beginseg 				name    "HAKAdanCH_scene" 		flags   OBJECT 			number  	2		include  "$(ZELDA_ROOT)/data/Hakadan_ch_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "HAKAdanCH_room_0" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Hakadan_ch_ROOM0.o" 		romalign 0x1000		endseg 
beginseg 				name    "HAKAdanCH_room_1" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Hakadan_ch_ROOM1.o" 		romalign 0x1000		endseg 
beginseg 				name    "HAKAdanCH_room_2" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Hakadan_ch_ROOM2.o" 		romalign 0x1000		endseg 
beginseg 				name    "HAKAdanCH_room_3" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Hakadan_ch_ROOM3.o" 		romalign 0x1000		endseg 
beginseg 				name    "HAKAdanCH_room_4" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Hakadan_ch_ROOM4.o" 		romalign 0x1000		endseg 
beginseg 				name    "HAKAdanCH_room_5" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Hakadan_ch_ROOM5.o" 		romalign 0x1000		endseg 
beginseg 				name    "HAKAdanCH_room_6" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Hakadan_ch_ROOM6.o" 		romalign 0x1000		endseg 

beginseg 				name    "ice_doukutu_scene" 		flags   OBJECT 			number  	2		include  "$(ZELDA_ROOT)/data/Ice_doukutu_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "ice_doukutu_room_0" 		flags   OBJECT 			number  	3		include  "$(ZELDA_ROOT)/data/Ice_doukutu_ROOM0.o" 		romalign 0x1000		endseg 
beginseg 				name    "ice_doukutu_room_1" 		flags   OBJECT 			number  	3		include  "$(ZELDA_ROOT)/data/Ice_doukutu_ROOM1.o" 		romalign 0x1000		endseg 
beginseg 				name    "ice_doukutu_room_2" 		flags   OBJECT 			number  	3		include  "$(ZELDA_ROOT)/data/Ice_doukutu_ROOM2.o" 		romalign 0x1000		endseg 
beginseg 				name    "ice_doukutu_room_3" 		flags   OBJECT 			number  	3		include  "$(ZELDA_ROOT)/data/Ice_doukutu_ROOM3.o" 		romalign 0x1000		endseg 
beginseg 				name    "ice_doukutu_room_4" 		flags   OBJECT 			number  	3		include  "$(ZELDA_ROOT)/data/Ice_doukutu_ROOM4.o" 		romalign 0x1000		endseg 
beginseg 				name    "ice_doukutu_room_5" 		flags   OBJECT 			number  	3		include  "$(ZELDA_ROOT)/data/Ice_doukutu_ROOM5.o" 		romalign 0x1000		endseg 
beginseg 				name    "ice_doukutu_room_6" 		flags   OBJECT 			number  	3		include  "$(ZELDA_ROOT)/data/Ice_doukutu_ROOM6.o" 		romalign 0x1000		endseg 
beginseg 				name    "ice_doukutu_room_7" 		flags   OBJECT 			number  	3		include  "$(ZELDA_ROOT)/data/Ice_doukutu_ROOM7.o" 		romalign 0x1000		endseg 
beginseg 				name    "ice_doukutu_room_8" 		flags   OBJECT 			number  	3		include  "$(ZELDA_ROOT)/data/Ice_doukutu_ROOM8.o" 		romalign 0x1000		endseg 
beginseg 				name    "ice_doukutu_room_9" 		flags   OBJECT 			number  	3		include  "$(ZELDA_ROOT)/data/Ice_doukutu_ROOM9.o" 		romalign 0x1000		endseg 
beginseg 				name    "ice_doukutu_room_10" 		flags   OBJECT 			number  	3		include  "$(ZELDA_ROOT)/data/Ice_doukutu_ROOM10.o" 		romalign 0x1000		endseg 
beginseg 				name    "ice_doukutu_room_11" 		flags   OBJECT 			number  	3		include  "$(ZELDA_ROOT)/data/Ice_doukutu_ROOM11.o" 		romalign 0x1000		endseg 

beginseg 				name    "men_scene" 		flags   OBJECT 			number  		2		include  "$(ZELDA_ROOT)/data/Men_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "men_room_0" 		flags   OBJECT 			number  		3		include  	"$(ZELDA_ROOT)/data/Men_ROOM0.o" 		romalign 0x1000		endseg 
beginseg 				name    "men_room_1" 		flags   OBJECT 			number  		3		include  	"$(ZELDA_ROOT)/data/Men_ROOM1.o" 		romalign 0x1000		endseg 
beginseg 				name    "men_room_2" 		flags   OBJECT 			number  		3		include  	"$(ZELDA_ROOT)/data/Men_ROOM2.o" 		romalign 0x1000		endseg 
beginseg 				name    "men_room_3" 		flags   OBJECT 			number  		3		include  	"$(ZELDA_ROOT)/data/Men_ROOM3.o" 		romalign 0x1000		endseg 
beginseg 				name    "men_room_4" 		flags   OBJECT 			number  		3		include  	"$(ZELDA_ROOT)/data/Men_ROOM4.o" 		romalign 0x1000		endseg 
beginseg 				name    "men_room_5" 		flags   OBJECT 			number  		3		include  	"$(ZELDA_ROOT)/data/Men_ROOM5.o" 		romalign 0x1000		endseg 
beginseg 				name    "men_room_6" 		flags   OBJECT 			number  		3		include  	"$(ZELDA_ROOT)/data/Men_ROOM6.o" 		romalign 0x1000		endseg 
beginseg 				name    "men_room_7" 		flags   OBJECT 			number  		3		include  	"$(ZELDA_ROOT)/data/Men_ROOM7.o" 		romalign 0x1000		endseg 
beginseg 				name    "men_room_8" 		flags   OBJECT 			number  		3		include  	"$(ZELDA_ROOT)/data/Men_ROOM8.o" 		romalign 0x1000		endseg 
beginseg 				name    "men_room_9" 		flags   OBJECT 			number  		3		include  	"$(ZELDA_ROOT)/data/Men_ROOM9.o" 		romalign 0x1000		endseg 
beginseg 				name    "men_room_10" 		flags   OBJECT 			number  		3		include  	"$(ZELDA_ROOT)/data/Men_ROOM10.o" 		romalign 0x1000		endseg 

beginseg 				name    "ganontika_scene" 		flags   OBJECT 			number   	2		include  "$(ZELDA_ROOT)/data/Ganontika_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "ganontika_room_0" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Ganontika_ROOM0.o" 		romalign 0x1000		endseg 
beginseg 				name    "ganontika_room_1" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Ganontika_ROOM1.o" 		romalign 0x1000		endseg 
beginseg 				name    "ganontika_room_2" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Ganontika_ROOM2.o" 		romalign 0x1000		endseg 
beginseg 				name    "ganontika_room_3" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Ganontika_ROOM3.o" 		romalign 0x1000		endseg 
beginseg 				name    "ganontika_room_4" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Ganontika_ROOM4.o" 		romalign 0x1000		endseg 
beginseg 				name    "ganontika_room_5" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Ganontika_ROOM5.o" 		romalign 0x1000		endseg 
beginseg 				name    "ganontika_room_6" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Ganontika_ROOM6.o" 		romalign 0x1000		endseg 
beginseg 				name    "ganontika_room_7" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Ganontika_ROOM7.o" 		romalign 0x1000		endseg 
beginseg 				name    "ganontika_room_8" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Ganontika_ROOM8.o" 		romalign 0x1000		endseg 
beginseg 				name    "ganontika_room_9" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Ganontika_ROOM9.o" 		romalign 0x1000		endseg 
beginseg 				name    "ganontika_room_10" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Ganontika_ROOM10.o" 		romalign 0x1000		endseg 
beginseg 				name    "ganontika_room_11" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Ganontika_ROOM11.o" 		romalign 0x1000		endseg 
beginseg 				name    "ganontika_room_12" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Ganontika_ROOM12.o" 		romalign 0x1000		endseg 
beginseg 				name    "ganontika_room_13" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Ganontika_ROOM13.o" 		romalign 0x1000		endseg 
beginseg 				name    "ganontika_room_14" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Ganontika_ROOM14.o" 		romalign 0x1000		endseg 
beginseg 				name    "ganontika_room_15" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Ganontika_ROOM15.o" 		romalign 0x1000		endseg 
beginseg 				name    "ganontika_room_16" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Ganontika_ROOM16.o" 		romalign 0x1000		endseg 
beginseg 				name    "ganontika_room_17" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Ganontika_ROOM17.o" 		romalign 0x1000		endseg 
beginseg 				name    "ganontika_room_18" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Ganontika_ROOM18.o" 		romalign 0x1000		endseg 
beginseg 				name    "ganontika_room_19" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Ganontika_ROOM19.o" 		romalign 0x1000		endseg 

# 2640 "../spec.segment"






















beginseg 				name    "spot00_scene" 		flags   OBJECT 			number   	2		include  "$(ZELDA_ROOT)/data/Spot00_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "spot00_room_0" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Spot00_ROOM0.o" 		romalign 0x1000		endseg 

beginseg 				name    "spot01_scene" 		flags   OBJECT 			number   	2		include  "$(ZELDA_ROOT)/data/Spot01_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "spot01_room_0" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Spot01_ROOM0.o" 		romalign 0x1000		endseg 

beginseg 				name    "spot02_scene" 		flags   OBJECT 			number   	2		include  "$(ZELDA_ROOT)/data/Spot02_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "spot02_room_0" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Spot02_ROOM0.o" 		romalign 0x1000		endseg 
beginseg 				name    "spot02_room_1" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Spot02_ROOM1.o" 		romalign 0x1000		endseg 

beginseg 				name    "spot03_scene" 		flags   OBJECT 			number   	2		include  "$(ZELDA_ROOT)/data/Spot03_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "spot03_room_0" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Spot03_ROOM0.o" 		romalign 0x1000		endseg 
beginseg 				name    "spot03_room_1" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Spot03_ROOM1.o" 		romalign 0x1000		endseg 

beginseg 				name    "spot04_scene" 		flags   OBJECT 			number   	2		include  "$(ZELDA_ROOT)/data/Spot04_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "spot04_room_0" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Spot04_ROOM0.o" 		romalign 0x1000		endseg 
beginseg 				name    "spot04_room_1" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Spot04_ROOM1.o" 		romalign 0x1000		endseg 
beginseg 				name    "spot04_room_2" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Spot04_ROOM2.o" 		romalign 0x1000		endseg 

beginseg 				name    "spot05_scene" 		flags   OBJECT 			number   	2		include  "$(ZELDA_ROOT)/data/Spot05_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "spot05_room_0" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Spot05_ROOM0.o" 		romalign 0x1000		endseg 

beginseg 				name    "spot06_scene" 		flags   OBJECT 			number   	2		include  "$(ZELDA_ROOT)/data/Spot06_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "spot06_room_0" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Spot06_ROOM0.o" 		romalign 0x1000		endseg 

beginseg 				name    "spot07_scene" 		flags   OBJECT 			number   	2		include  "$(ZELDA_ROOT)/data/Spot07_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "spot07_room_0" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Spot07_ROOM0.o" 		romalign 0x1000		endseg 
beginseg 				name    "spot07_room_1" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Spot07_ROOM1.o" 		romalign 0x1000		endseg 

beginseg 				name    "spot08_scene" 		flags   OBJECT 			number   	2		include  "$(ZELDA_ROOT)/data/Spot08_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "spot08_room_0" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Spot08_ROOM0.o" 		romalign 0x1000		endseg 

beginseg 				name    "spot09_scene" 		flags   OBJECT 			number   	2		include  "$(ZELDA_ROOT)/data/Spot09_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "spot09_room_0" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Spot09_ROOM0.o" 		romalign 0x1000		endseg 

beginseg 				name    "spot10_scene" 		flags   OBJECT 			number   	2		include  "$(ZELDA_ROOT)/data/Spot10_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "spot10_room_0" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Spot10_ROOM0.o" 		romalign 0x1000		endseg 
beginseg 				name    "spot10_room_1" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Spot10_ROOM1.o" 		romalign 0x1000		endseg 
beginseg 				name    "spot10_room_2" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Spot10_ROOM2.o" 		romalign 0x1000		endseg 
beginseg 				name    "spot10_room_3" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Spot10_ROOM3.o" 		romalign 0x1000		endseg 
beginseg 				name    "spot10_room_4" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Spot10_ROOM4.o" 		romalign 0x1000		endseg 
beginseg 				name    "spot10_room_5" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Spot10_ROOM5.o" 		romalign 0x1000		endseg 
beginseg 				name    "spot10_room_6" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Spot10_ROOM6.o" 		romalign 0x1000		endseg 
beginseg 				name    "spot10_room_7" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Spot10_ROOM7.o" 		romalign 0x1000		endseg 
beginseg 				name    "spot10_room_8" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Spot10_ROOM8.o" 		romalign 0x1000		endseg 
beginseg 				name    "spot10_room_9" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Spot10_ROOM9.o" 		romalign 0x1000		endseg 

beginseg 				name    "spot11_scene" 		flags   OBJECT 			number   	2		include  "$(ZELDA_ROOT)/data/Spot11_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "spot11_room_0" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Spot11_ROOM0.o" 		romalign 0x1000		endseg 

beginseg 				name    "spot12_scene" 		flags   OBJECT 			number   	2		include  "$(ZELDA_ROOT)/data/Spot12_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "spot12_room_0" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Spot12_ROOM0.o" 		romalign 0x1000		endseg 
beginseg 				name    "spot12_room_1" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Spot12_ROOM1.o" 		romalign 0x1000		endseg 

beginseg 				name    "spot13_scene" 		flags   OBJECT 			number   	2		include  "$(ZELDA_ROOT)/data/Spot13_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "spot13_room_0" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Spot13_ROOM0.o" 		romalign 0x1000		endseg 
beginseg 				name    "spot13_room_1" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Spot13_ROOM1.o" 		romalign 0x1000		endseg 

beginseg 				name    "spot15_scene" 		flags   OBJECT 			number   	2		include  "$(ZELDA_ROOT)/data/Spot15_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "spot15_room_0" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Spot15_ROOM0.o" 		romalign 0x1000		endseg 

beginseg 				name    "spot16_scene" 		flags   OBJECT 			number   	2		include  "$(ZELDA_ROOT)/data/Spot16_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "spot16_room_0" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Spot16_ROOM0.o" 		romalign 0x1000		endseg 

beginseg 				name    "spot17_scene" 		flags   OBJECT 			number   	2		include  "$(ZELDA_ROOT)/data/Spot17_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "spot17_room_0" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Spot17_ROOM0.o" 		romalign 0x1000		endseg 
beginseg 				name    "spot17_room_1" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Spot17_ROOM1.o" 		romalign 0x1000		endseg 

beginseg 				name    "spot18_scene" 		flags   OBJECT 			number   	2		include  "$(ZELDA_ROOT)/data/Spot18_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "spot18_room_0" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Spot18_ROOM0.o" 		romalign 0x1000		endseg 
beginseg 				name    "spot18_room_1" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Spot18_ROOM1.o" 		romalign 0x1000		endseg 
beginseg 				name    "spot18_room_2" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Spot18_ROOM2.o" 		romalign 0x1000		endseg 
beginseg 				name    "spot18_room_3" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Spot18_ROOM3.o" 		romalign 0x1000		endseg 






	
beginseg 				name    "market_day_scene" 		flags   OBJECT 			number   	2		include  "$(ZELDA_ROOT)/data/Market_day_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "market_day_room_0" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Market_day_ROOM0.o" 		romalign 0x1000		endseg 

beginseg 				name    "market_night_scene" 		flags   OBJECT 			number   	2		include  "$(ZELDA_ROOT)/data/Market_night_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "market_night_room_0" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Market_night_ROOM0.o" 		romalign 0x1000		endseg 










beginseg 				name    "kenjyanoma_scene" 		flags   OBJECT 			number  	2		include  "$(ZELDA_ROOT)/data/Kenjyanoma_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "kenjyanoma_room_0" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Kenjyanoma_ROOM0.o" 		romalign 0x1000		endseg 

beginseg 				name    "tokinoma_scene" 		flags   OBJECT 			number  	2		include  "$(ZELDA_ROOT)/data/Tokinoma_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "tokinoma_room_0" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Tokinoma_ROOM0.o" 		romalign 0x1000		endseg 
beginseg 				name    "tokinoma_room_1" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Tokinoma_ROOM1.o" 		romalign 0x1000		endseg 






beginseg 				name    "link_home_scene" 		flags   OBJECT 			number  	2		include  "$(ZELDA_ROOT)/data/Link_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "link_home_room_0" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Link_ROOM0.o" 		romalign 0x1000		endseg 

beginseg 				name    "kokiri_shop_scene" 		flags   OBJECT 			number  	2		include  "$(ZELDA_ROOT)/data/Kokiri_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "kokiri_shop_room_0" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Kokiri_ROOM0.o" 		romalign 0x1000		endseg 

beginseg 				name    "kokiri_home_scene" 		flags   OBJECT 			number  	2		include  "$(ZELDA_ROOT)/data/K_Home_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "kokiri_home_room_0" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/K_Home_ROOM0.o" 		romalign 0x1000		endseg 

beginseg 				name    "kakusiana_scene" 		flags   OBJECT 			number  	2		include  "$(ZELDA_ROOT)/data/Kakusiana_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "kakusiana_room_0" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Kakusiana_ROOM0.o" 		romalign 0x1000		endseg 
beginseg 				name    "kakusiana_room_1" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Kakusiana_ROOM1.o" 		romalign 0x1000		endseg 
beginseg 				name    "kakusiana_room_2" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Kakusiana_ROOM2.o" 		romalign 0x1000		endseg 
beginseg 				name    "kakusiana_room_3" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Kakusiana_ROOM3.o" 		romalign 0x1000		endseg 
beginseg 				name    "kakusiana_room_4" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Kakusiana_ROOM4.o" 		romalign 0x1000		endseg 
beginseg 				name    "kakusiana_room_5" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Kakusiana_ROOM5.o" 		romalign 0x1000		endseg 
beginseg 				name    "kakusiana_room_6" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Kakusiana_ROOM6.o" 		romalign 0x1000		endseg 
beginseg 				name    "kakusiana_room_7" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Kakusiana_ROOM7.o" 		romalign 0x1000		endseg 
beginseg 				name    "kakusiana_room_8" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Kakusiana_ROOM8.o" 		romalign 0x1000		endseg 
beginseg 				name    "kakusiana_room_9" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Kakusiana_ROOM9.o" 		romalign 0x1000		endseg 
beginseg 				name    "kakusiana_room_10" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Kakusiana_ROOM10.o" 		romalign 0x1000		endseg 
beginseg 				name    "kakusiana_room_11" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Kakusiana_ROOM11.o" 		romalign 0x1000		endseg 
beginseg 				name    "kakusiana_room_12" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Kakusiana_ROOM12.o" 		romalign 0x1000		endseg 
beginseg 				name    "kakusiana_room_13" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Kakusiana_ROOM13.o" 		romalign 0x1000		endseg 

beginseg 				name    "entra_scene" 		flags   OBJECT 			number  		2		include  "$(ZELDA_ROOT)/data/Entra_day_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "entra_room_0" 		flags   OBJECT 			number  		3		include  	"$(ZELDA_ROOT)/data/Entra_day_ROOM0.o" 		romalign 0x1000		endseg 

beginseg 				name    "moribossroom_scene" 		flags   OBJECT 			number  	2		include  "$(ZELDA_ROOT)/data/Moriboss_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "moribossroom_room_0" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Moriboss_ROOM0.o" 		romalign 0x1000		endseg 
beginseg 				name    "moribossroom_room_1" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Moriboss_ROOM1.o" 		romalign 0x1000		endseg 

beginseg 				name    "syatekijyou_scene" 		flags   OBJECT 			number  	2		include  "$(ZELDA_ROOT)/data/Syatekijyou_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "syatekijyou_room_0" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Syatekijyou_ROOM0.o" 		romalign 0x1000		endseg 

beginseg 				name    "shop1_scene" 		flags   OBJECT 			number  		2		include  "$(ZELDA_ROOT)/data/Shop_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "shop1_room_0" 		flags   OBJECT 			number  		3		include  	"$(ZELDA_ROOT)/data/Shop_ROOM0.o" 		romalign 0x1000		endseg 

beginseg 				name    "hairal_niwa_scene" 		flags   OBJECT 			number  		2		include  "$(ZELDA_ROOT)/data/Hairal_niwa_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "hairal_niwa_room_0" 		flags   OBJECT 			number  		3		include  	"$(ZELDA_ROOT)/data/Hairal_niwa_ROOM0.o" 		romalign 0x1000		endseg 

beginseg 				name    "ganon_tou_scene" 		flags   OBJECT 			number  		2		include  "$(ZELDA_ROOT)/data/Ganon_tou_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "ganon_tou_room_0" 		flags   OBJECT 			number  		3		include  	"$(ZELDA_ROOT)/data/Ganon_tou_ROOM0.o" 		romalign 0x1000		endseg 






beginseg 				name    "market_alley_scene" 		flags   OBJECT 			number   	2		include  "$(ZELDA_ROOT)/data/Market_alley_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "market_alley_room_0" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Market_alley_ROOM0.o" 		romalign 0x1000		endseg 

beginseg 				name    "spot20_scene" 		flags   OBJECT 			number   	2		include  "$(ZELDA_ROOT)/data/Spot20_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "spot20_room_0" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Spot20_ROOM0.o" 		romalign 0x1000		endseg 

beginseg 				name    "market_ruins_scene" 		flags   OBJECT 			number   	2		include  "$(ZELDA_ROOT)/data/Market_ruins_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "market_ruins_room_0" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Market_ruins_ROOM0.o" 		romalign 0x1000		endseg 

beginseg 				name    "entra_n_scene" 		flags   OBJECT 			number  	2		include  "$(ZELDA_ROOT)/data/Entra_night_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "entra_n_room_0" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Entra_night_ROOM0.o" 		romalign 0x1000		endseg 

beginseg 				name    "enrui_scene" 		flags   OBJECT 			number  		2		include  "$(ZELDA_ROOT)/data/Entra_ruins_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "enrui_room_0" 		flags   OBJECT 			number  		3		include  	"$(ZELDA_ROOT)/data/Entra_ruins_ROOM0.o" 		romalign 0x1000		endseg 

beginseg 				name    "market_alley_n_scene" 		flags   OBJECT 			number   2		include  "$(ZELDA_ROOT)/data/Market_alley_n_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "market_alley_n_room_0" 		flags   OBJECT 			number  3		include  	"$(ZELDA_ROOT)/data/Market_alley_n_ROOM0.o" 		romalign 0x1000		endseg 

beginseg 				name    "hiral_demo_scene" 		flags   OBJECT 			number   2		include  	"$(ZELDA_ROOT)/data/Hiral_demo_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "hiral_demo_room_0" 		flags   OBJECT 			number  3		include  	"$(ZELDA_ROOT)/data/Hiral_demo_ROOM0.o" 		romalign 0x1000		endseg 






beginseg 				name    "kokiri_home3_scene" 		flags   OBJECT 			number  	2		include  "$(ZELDA_ROOT)/data/K_Home3_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "kokiri_home3_room_0" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/K_Home3_ROOM0.o" 		romalign 0x1000		endseg 

beginseg 				name    "malon_stable_scene" 		flags   OBJECT 			number  		2		include  "$(ZELDA_ROOT)/data/Stable_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "malon_stable_room_0" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Stable_ROOM0.o" 		romalign 0x1000		endseg 

beginseg 				name    "kakariko_scene" 		flags   OBJECT 			number  	2		include  "$(ZELDA_ROOT)/data/Kakariko_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "kakariko_room_0" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Kakariko_ROOM0.o" 		romalign 0x1000		endseg 

beginseg 				name    "bdan_boss_scene" 		flags   OBJECT 			number  	2		include  "$(ZELDA_ROOT)/data/Bdan_boss_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "bdan_boss_room_0" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Bdan_boss_ROOM0.o" 		romalign 0x1000		endseg 
beginseg 				name    "bdan_boss_room_1" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Bdan_boss_ROOM1.o" 		romalign 0x1000		endseg 

beginseg 				name    "FIRE_bs_scene" 		flags   OBJECT 			number  	2		include  "$(ZELDA_ROOT)/data/Fire_bs_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "FIRE_bs_room_0" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Fire_bs_ROOM0.o" 		romalign 0x1000		endseg 
beginseg 				name    "FIRE_bs_room_1" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Fire_bs_ROOM1.o" 		romalign 0x1000		endseg 

beginseg 				name    "hut_scene" 		flags   OBJECT 			number  	2		include  "$(ZELDA_ROOT)/data/HUT_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "hut_room_0" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/HUT_ROOM0.o" 		romalign 0x1000		endseg 

beginseg 				name    "daiyousei_izumi_scene" 		flags   OBJECT 			number   2		include  "$(ZELDA_ROOT)/data/Daiyousei_izumi_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "daiyousei_izumi_room_0" 		flags   OBJECT 			number  3		include   "$(ZELDA_ROOT)/data/Daiyousei_izumi_ROOM0.o" 		romalign 0x1000		endseg 

beginseg 				name    "hakaana_scene" 		flags   OBJECT 			number  	2		include  "$(ZELDA_ROOT)/data/Hakaana_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "hakaana_room_0" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Hakaana_ROOM0.o" 		romalign 0x1000		endseg 

beginseg 				name    "yousei_izumi_tate_scene" 		flags   OBJECT 			number  2		include  "$(ZELDA_ROOT)/data/Yousei_izumi_tate_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "yousei_izumi_tate_room_0" 		flags   OBJECT 			number  3		include  "$(ZELDA_ROOT)/data/Yousei_izumi_tate_ROOM0.o" 		romalign 0x1000		endseg 

beginseg 				name    "yousei_izumi_yoko_scene" 		flags   OBJECT 			number  2		include  "$(ZELDA_ROOT)/data/Yousei_izumi_yoko_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "yousei_izumi_yoko_room_0" 		flags   OBJECT 			number  3		include  "$(ZELDA_ROOT)/data/Yousei_izumi_yoko_ROOM0.o" 		romalign 0x1000		endseg 

beginseg 				name    "golon_scene" 		flags   OBJECT 			number  2		include  "$(ZELDA_ROOT)/data/Shop_golon_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "golon_room_0" 		flags   OBJECT 			number  3		include  "$(ZELDA_ROOT)/data/Shop_golon_ROOM0.o" 		romalign 0x1000		endseg 

beginseg 				name    "zoora_scene" 		flags   OBJECT 			number  2		include  "$(ZELDA_ROOT)/data/Zoora_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "zoora_room_0" 		flags   OBJECT 			number  3		include  "$(ZELDA_ROOT)/data/Zoora_ROOM0.o" 		romalign 0x1000		endseg 

beginseg 				name    "drag_scene" 		flags   OBJECT 			number  2		include  "$(ZELDA_ROOT)/data/Shop_drag_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "drag_room_0" 		flags   OBJECT 			number  3		include  "$(ZELDA_ROOT)/data/Shop_drag_ROOM0.o" 		romalign 0x1000		endseg 

beginseg 				name    "alley_shop_scene" 		flags   OBJECT 			number  2		include  "$(ZELDA_ROOT)/data/Shop_alley_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "alley_shop_room_0" 		flags   OBJECT 			number  3		include  "$(ZELDA_ROOT)/data/Shop_alley_ROOM0.o" 		romalign 0x1000		endseg 

beginseg 				name    "night_shop_scene" 		flags   OBJECT 			number  2		include  "$(ZELDA_ROOT)/data/Shop_night_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "night_shop_room_0" 		flags   OBJECT 			number  3		include  "$(ZELDA_ROOT)/data/Shop_night_ROOM0.o" 		romalign 0x1000		endseg 

beginseg 				name    "impa_scene" 		flags   OBJECT 			number  2		include  "$(ZELDA_ROOT)/data/Kakariko_impa_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "impa_room_0" 		flags   OBJECT 			number  3		include  "$(ZELDA_ROOT)/data/Kakariko_impa_ROOM0.o" 		romalign 0x1000		endseg 

beginseg 				name    "labo_scene" 		flags   OBJECT 			number  2		include  "$(ZELDA_ROOT)/data/Labo_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "labo_room_0" 		flags   OBJECT 			number  3		include  "$(ZELDA_ROOT)/data/Labo_ROOM0.o" 		romalign 0x1000		endseg 

beginseg 				name    "tent_scene" 		flags   OBJECT 			number  2		include  "$(ZELDA_ROOT)/data/Tent_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "tent_room_0" 		flags   OBJECT 			number  3		include  "$(ZELDA_ROOT)/data/Tent_ROOM0.o" 		romalign 0x1000		endseg 

beginseg 				name    "nakaniwa_scene" 		flags   OBJECT 			number  	2		include  "$(ZELDA_ROOT)/data/Nakaniwa_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "nakaniwa_room_0" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Nakaniwa_ROOM0.o" 		romalign 0x1000		endseg 

beginseg 				name    "ddan_boss_scene" 		flags   OBJECT 			number  	2		include  "$(ZELDA_ROOT)/data/Ddan_boss_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "ddan_boss_room_0" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Ddan_boss_ROOM0.o" 		romalign 0x1000		endseg 
beginseg 				name    "ddan_boss_room_1" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Ddan_boss_ROOM1.o" 		romalign 0x1000		endseg 

beginseg 				name    "ydan_boss_scene" 		flags   OBJECT 			number  	2		include  "$(ZELDA_ROOT)/data/Ydan_boss_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "ydan_boss_room_0" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Ydan_boss_ROOM0.o" 		romalign 0x1000		endseg 
beginseg 				name    "ydan_boss_room_1" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Ydan_boss_ROOM1.o" 		romalign 0x1000		endseg 

beginseg 				name    "HAKAdan_bs_scene" 		flags   OBJECT 			number  	2		include  "$(ZELDA_ROOT)/data/Hakadan_boss_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "HAKAdan_bs_room_0" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Hakadan_boss_ROOM0.o" 		romalign 0x1000		endseg 
beginseg 				name    "HAKAdan_bs_room_1" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Hakadan_boss_ROOM1.o" 		romalign 0x1000		endseg 

beginseg 				name    "MIZUsin_bs_scene" 		flags   OBJECT 			number  	2		include  "$(ZELDA_ROOT)/data/Mizusin_boss_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "MIZUsin_bs_room_0" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Mizusin_boss_ROOM0.o" 		romalign 0x1000		endseg 
beginseg 				name    "MIZUsin_bs_room_1" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Mizusin_boss_ROOM1.o" 		romalign 0x1000		endseg 

beginseg 				name    "ganon_scene" 		flags   OBJECT 			number  		2		include  "$(ZELDA_ROOT)/data/Ganon_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "ganon_room_0" 		flags   OBJECT 			number  		3		include  	"$(ZELDA_ROOT)/data/Ganon_ROOM0.o" 		romalign 0x1000		endseg 
beginseg 				name    "ganon_room_1" 		flags   OBJECT 			number  		3		include  	"$(ZELDA_ROOT)/data/Ganon_ROOM1.o" 		romalign 0x1000		endseg 
beginseg 				name    "ganon_room_2" 		flags   OBJECT 			number  		3		include  	"$(ZELDA_ROOT)/data/Ganon_ROOM2.o" 		romalign 0x1000		endseg 
beginseg 				name    "ganon_room_3" 		flags   OBJECT 			number  		3		include  	"$(ZELDA_ROOT)/data/Ganon_ROOM3.o" 		romalign 0x1000		endseg 
beginseg 				name    "ganon_room_4" 		flags   OBJECT 			number  		3		include  	"$(ZELDA_ROOT)/data/Ganon_ROOM4.o" 		romalign 0x1000		endseg 
beginseg 				name    "ganon_room_5" 		flags   OBJECT 			number  		3		include  	"$(ZELDA_ROOT)/data/Ganon_ROOM5.o" 		romalign 0x1000		endseg 
beginseg 				name    "ganon_room_6" 		flags   OBJECT 			number  		3		include  	"$(ZELDA_ROOT)/data/Ganon_ROOM6.o" 		romalign 0x1000		endseg 
beginseg 				name    "ganon_room_7" 		flags   OBJECT 			number  		3		include  	"$(ZELDA_ROOT)/data/Ganon_ROOM7.o" 		romalign 0x1000		endseg 
beginseg 				name    "ganon_room_8" 		flags   OBJECT 			number  		3		include  	"$(ZELDA_ROOT)/data/Ganon_ROOM8.o" 		romalign 0x1000		endseg 
beginseg 				name    "ganon_room_9" 		flags   OBJECT 			number  		3		include  	"$(ZELDA_ROOT)/data/Ganon_ROOM9.o" 		romalign 0x1000		endseg 

beginseg 				name    "ganon_boss_scene" 		flags   OBJECT 			number  	2		include  "$(ZELDA_ROOT)/data/Ganon_boss_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "ganon_boss_room_0" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Ganon_boss_ROOM0.o" 		romalign 0x1000		endseg 

beginseg 				name    "jyasinboss_scene" 		flags   OBJECT 			number  	2		include  "$(ZELDA_ROOT)/data/Jyasinzou_boss_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "jyasinboss_room_0" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Jyasinzou_boss_ROOM0.o" 		romalign 0x1000		endseg 
beginseg 				name    "jyasinboss_room_1" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Jyasinzou_boss_ROOM1.o" 		romalign 0x1000		endseg 
beginseg 				name    "jyasinboss_room_2" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Jyasinzou_boss_ROOM2.o" 		romalign 0x1000		endseg 
beginseg 				name    "jyasinboss_room_3" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Jyasinzou_boss_ROOM3.o" 		romalign 0x1000		endseg 

beginseg 				name    "kokiri_home4_scene" 		flags   OBJECT 			number  	2		include  "$(ZELDA_ROOT)/data/K_Home4_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "kokiri_home4_room_0" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/K_Home4_ROOM0.o" 		romalign 0x1000		endseg 

beginseg 				name    "kokiri_home5_scene" 		flags   OBJECT 			number  	2		include  "$(ZELDA_ROOT)/data/K_Home5_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "kokiri_home5_room_0" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/K_Home5_ROOM0.o" 		romalign 0x1000		endseg 

beginseg 				name    "ganon_final_scene" 		flags   OBJECT 			number  	2		include  "$(ZELDA_ROOT)/data/Ganon_final_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "ganon_final_room_0" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Ganon_final_ROOM0.o" 		romalign 0x1000		endseg 

beginseg 				name    "kakariko3_scene" 		flags   OBJECT 			number  	2		include  "$(ZELDA_ROOT)/data/Kakariko_home3_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "kakariko3_room_0" 		flags   OBJECT 			number  	3		include  "$(ZELDA_ROOT)/data/Kakariko_home3_ROOM0.o" 		romalign 0x1000		endseg 






beginseg 				name    "hakasitarelay_scene" 		flags   OBJECT 			number  		2		include  "$(ZELDA_ROOT)/data/Hakasitarelay_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "hakasitarelay_room_0" 		flags   OBJECT 			number  		3		include  	"$(ZELDA_ROOT)/data/Hakasitarelay_ROOM0.o" 		romalign 0x1000		endseg 
beginseg 				name    "hakasitarelay_room_1" 		flags   OBJECT 			number  		3		include  	"$(ZELDA_ROOT)/data/Hakasitarelay_ROOM1.o" 		romalign 0x1000		endseg 
beginseg 				name    "hakasitarelay_room_2" 		flags   OBJECT 			number  		3		include  	"$(ZELDA_ROOT)/data/Hakasitarelay_ROOM2.o" 		romalign 0x1000		endseg 
beginseg 				name    "hakasitarelay_room_3" 		flags   OBJECT 			number  		3		include  	"$(ZELDA_ROOT)/data/Hakasitarelay_ROOM3.o" 		romalign 0x1000		endseg 
beginseg 				name    "hakasitarelay_room_4" 		flags   OBJECT 			number  		3		include  	"$(ZELDA_ROOT)/data/Hakasitarelay_ROOM4.o" 		romalign 0x1000		endseg 
beginseg 				name    "hakasitarelay_room_5" 		flags   OBJECT 			number  		3		include  	"$(ZELDA_ROOT)/data/Hakasitarelay_ROOM5.o" 		romalign 0x1000		endseg 
beginseg 				name    "hakasitarelay_room_6" 		flags   OBJECT 			number  		3		include  	"$(ZELDA_ROOT)/data/Hakasitarelay_ROOM6.o" 		romalign 0x1000		endseg 

beginseg 				name    "shrine_scene" 		flags   OBJECT 			number   	2		include  "$(ZELDA_ROOT)/data/Shrine_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "shrine_room_0" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Shrine_ROOM0.o" 		romalign 0x1000		endseg 

beginseg 				name    "turibori_scene" 		flags   OBJECT 			number   	2		include  "$(ZELDA_ROOT)/data/Turibori_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "turibori_room_0" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Turibori_ROOM0.o" 		romalign 0x1000		endseg 

beginseg 				name    "shrine_n_scene" 		flags   OBJECT 			number   	2		include  "$(ZELDA_ROOT)/data/Shrine_n_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "shrine_n_room_0" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Shrine_n_ROOM0.o" 		romalign 0x1000		endseg 

beginseg 				name    "shrine_r_scene" 		flags   OBJECT 			number   	2		include  "$(ZELDA_ROOT)/data/Shrine_r_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "shrine_r_room_0" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Shrine_r_ROOM0.o" 		romalign 0x1000		endseg 

beginseg 				name    "hakaana2_scene" 		flags   OBJECT 			number  	2		include  "$(ZELDA_ROOT)/data/Hakaana2_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "hakaana2_room_0" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Hakaana2_ROOM0.o" 		romalign 0x1000		endseg 

beginseg 				name    "gerudoway_scene" 		flags   OBJECT 			number  	2		include  "$(ZELDA_ROOT)/data/Gerudoway_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "gerudoway_room_0" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Gerudoway_ROOM0.o" 		romalign 0x1000		endseg 
beginseg 				name    "gerudoway_room_1" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Gerudoway_ROOM1.o" 		romalign 0x1000		endseg 
beginseg 				name    "gerudoway_room_2" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Gerudoway_ROOM2.o" 		romalign 0x1000		endseg 
beginseg 				name    "gerudoway_room_3" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Gerudoway_ROOM3.o" 		romalign 0x1000		endseg 
beginseg 				name    "gerudoway_room_4" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Gerudoway_ROOM4.o" 		romalign 0x1000		endseg 
beginseg 				name    "gerudoway_room_5" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Gerudoway_ROOM5.o" 		romalign 0x1000		endseg 

beginseg 				name    "hairal_niwa_n_scene" 		flags   OBJECT 			number  	2		include  "$(ZELDA_ROOT)/data/Hairal_niwa_n_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "hairal_niwa_n_room_0" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Hairal_niwa_n_ROOM0.o" 		romalign 0x1000		endseg 

beginseg 				name    "bowling_scene" 		flags   OBJECT 			number  	2		include  "$(ZELDA_ROOT)/data/Bowling_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "bowling_room_0" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Bowling_ROOM0.o" 		romalign 0x1000		endseg 

beginseg 				name    "hakaana_ouke_scene" 		flags   OBJECT 			number  	2		include  "$(ZELDA_ROOT)/data/Hakaana_ouke_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "hakaana_ouke_room_0" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Hakaana_ouke_ROOM0.o" 		romalign 0x1000		endseg 
beginseg 				name    "hakaana_ouke_room_1" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Hakaana_ouke_ROOM1.o" 		romalign 0x1000		endseg 
beginseg 				name    "hakaana_ouke_room_2" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Hakaana_ouke_ROOM2.o" 		romalign 0x1000		endseg 

beginseg 				name    "hylia_labo_scene" 		flags   OBJECT 			number  	2		include  "$(ZELDA_ROOT)/data/Hylia_labo_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "hylia_labo_room_0" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Hylia_labo_ROOM0.o" 		romalign 0x1000		endseg 

beginseg 				name    "souko_scene" 		flags   OBJECT 			number  		2		include  "$(ZELDA_ROOT)/data/Souko_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "souko_room_0" 		flags   OBJECT 			number  		3		include  	"$(ZELDA_ROOT)/data/Souko_ROOM0.o" 		romalign 0x1000		endseg 
beginseg 				name    "souko_room_1" 		flags   OBJECT 			number  		3		include  	"$(ZELDA_ROOT)/data/Souko_ROOM1.o" 		romalign 0x1000		endseg 
beginseg 				name    "souko_room_2" 		flags   OBJECT 			number  		3		include  	"$(ZELDA_ROOT)/data/Souko_ROOM2.o" 		romalign 0x1000		endseg 

beginseg 				name    "miharigoya_scene" 		flags   OBJECT 			number  	2		include  "$(ZELDA_ROOT)/data/Miharigoya_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "miharigoya_room_0" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Miharigoya_ROOM0.o" 		romalign 0x1000		endseg 

beginseg 				name    "mahouya_scene" 		flags   OBJECT 			number  	2		include  "$(ZELDA_ROOT)/data/Mahouya_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "mahouya_room_0" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Mahouya_ROOM0.o" 		romalign 0x1000		endseg 

beginseg 				name    "takaraya_scene" 		flags   OBJECT 			number  	2		include  "$(ZELDA_ROOT)/data/Takaraya_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "takaraya_room_0" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Takaraya_ROOM0.o" 		romalign 0x1000		endseg 
beginseg 				name    "takaraya_room_1" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Takaraya_ROOM1.o" 		romalign 0x1000		endseg 
beginseg 				name    "takaraya_room_2" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Takaraya_ROOM2.o" 		romalign 0x1000		endseg 
beginseg 				name    "takaraya_room_3" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Takaraya_ROOM3.o" 		romalign 0x1000		endseg 
beginseg 				name    "takaraya_room_4" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Takaraya_ROOM4.o" 		romalign 0x1000		endseg 
beginseg 				name    "takaraya_room_5" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Takaraya_ROOM5.o" 		romalign 0x1000		endseg 
beginseg 				name    "takaraya_room_6" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Takaraya_ROOM6.o" 		romalign 0x1000		endseg 

beginseg 				name    "ganon_sonogo_scene" 		flags   OBJECT 			number  	2		include  "$(ZELDA_ROOT)/data/Ganon_sonogo_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "ganon_sonogo_room_0" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Ganon_sonogo_ROOM0.o" 		romalign 0x1000		endseg 
beginseg 				name    "ganon_sonogo_room_1" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Ganon_sonogo_ROOM1.o" 		romalign 0x1000		endseg 
beginseg 				name    "ganon_sonogo_room_2" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Ganon_sonogo_ROOM2.o" 		romalign 0x1000		endseg 
beginseg 				name    "ganon_sonogo_room_3" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Ganon_sonogo_ROOM3.o" 		romalign 0x1000		endseg 
beginseg 				name    "ganon_sonogo_room_4" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Ganon_sonogo_ROOM4.o" 		romalign 0x1000		endseg 

beginseg 				name    "ganon_demo_scene" 		flags   OBJECT 			number  	2		include  "$(ZELDA_ROOT)/data/Ganon_demo_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "ganon_demo_room_0" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Ganon_demo_ROOM0.o" 		romalign 0x1000		endseg 






beginseg 				name    "face_shop_scene" 		flags   OBJECT 			number  	2		include  "$(ZELDA_ROOT)/data/Shop_face_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "face_shop_room_0" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Shop_face_ROOM0.o" 		romalign 0x1000		endseg 

beginseg 				name    "kinsuta_scene" 		flags   OBJECT 			number  	2		include  "$(ZELDA_ROOT)/data/Kinsuta_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "kinsuta_room_0" 		flags   OBJECT 			number  	3		include  	"$(ZELDA_ROOT)/data/Kinsuta_ROOM0.o" 		romalign 0x1000		endseg 

beginseg 				name    "ganontikasonogo_scene" 		flags   OBJECT 			number   	2		include  "$(ZELDA_ROOT)/data/Ganontikasonogo_SCENE.o" 		romalign 0x1000		endseg 
beginseg 				name    "ganontikasonogo_room_0" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Ganontikasonogo_ROOM0.o" 		romalign 0x1000		endseg 
beginseg 				name    "ganontikasonogo_room_1" 		flags   OBJECT 			number   	3		include  	"$(ZELDA_ROOT)/data/Ganontikasonogo_ROOM1.o" 		romalign 0x1000		endseg 




















beginseg 				name    "bump_texture_static" 		flags   OBJECT 			number   8		include  "$(ZELDA_ROOT)/data/shape/bump_texture/bump_texture.o" 		romalign 0x1000		endseg 

beginseg 				name    "anime_model_1_static" 		flags   OBJECT 			number   8		include  	"$(ZELDA_ROOT)/data/shape/anime_model_1/anime_model_1.o" 		romalign 0x1000		endseg 
beginseg 				name    "anime_model_2_static" 		flags   OBJECT 			number   9		include  	"$(ZELDA_ROOT)/data/shape/anime_model_2/anime_model_2.o" 		romalign 0x1000		endseg 
beginseg 				name    "anime_model_3_static" 		flags   OBJECT 			number   10		include  	"$(ZELDA_ROOT)/data/shape/anime_model_3/anime_model_3.o" 		romalign 0x1000		endseg 
beginseg 				name    "anime_model_4_static" 		flags   OBJECT 			number   11		include  	"$(ZELDA_ROOT)/data/shape/anime_model_4/anime_model_4.o" 		romalign 0x1000		endseg 
beginseg 				name    "anime_model_5_static" 		flags   OBJECT 			number   12		include  	"$(ZELDA_ROOT)/data/shape/anime_model_5/anime_model_5.o" 		romalign 0x1000		endseg 
beginseg 				name    "anime_model_6_static" 		flags   OBJECT 			number   13		include  	"$(ZELDA_ROOT)/data/shape/anime_model_6/anime_model_6.o" 		romalign 0x1000		endseg 
beginseg 				name    "anime_texture_1_static" 		flags   OBJECT 			number   8		include  "$(ZELDA_ROOT)/data/shape/anime_texture_1/anime_texture_1.o" 		romalign 0x1000		endseg 
beginseg 				name    "anime_texture_2_static" 		flags   OBJECT 			number   9		include  "$(ZELDA_ROOT)/data/shape/anime_texture_2/anime_texture_2.o" 		romalign 0x1000		endseg 
beginseg 				name    "anime_texture_3_static" 		flags   OBJECT 			number   10		include  "$(ZELDA_ROOT)/data/shape/anime_texture_3/anime_texture_3.o" 		romalign 0x1000		endseg 
beginseg 				name    "anime_texture_4_static" 		flags   OBJECT 			number   11		include  "$(ZELDA_ROOT)/data/shape/anime_texture_4/anime_texture_4.o" 		romalign 0x1000		endseg 
beginseg 				name    "anime_texture_5_static" 		flags   OBJECT 			number   12		include  "$(ZELDA_ROOT)/data/shape/anime_texture_5/anime_texture_5.o" 		romalign 0x1000		endseg 
beginseg 				name    "anime_texture_6_static" 		flags   OBJECT 			number   13		include  "$(ZELDA_ROOT)/data/shape/anime_texture_6/anime_texture_6.o" 		romalign 0x1000		endseg 

beginseg 				name    "softsprite_matrix_static" 		flags   OBJECT 			number   1		include  "$(ZELDA_ROOT)/data/shape/softsprite_matrix/softsprite_matrix.o" 		romalign 0x1000		endseg 

beginseg 				name    "hilite" 		flags   OBJECT 			number   		7		include  	"z_hilite.o" 		romalign 0x1000		endseg 

 






# 4667 "../spec.segment"

# 1133 "../spec"
















 


beginwave
	name "zelda"
	include "boot"
	include "dmadata"

 
	include "Audiobank"
	include "Audioseq"
	include "Audiotable"

 
	include "hilite"

	include "kanji"

	include "link_animetion"


 










	include	"icon_item_static"
	include	"icon_item_24_static"
	include	"icon_item_field_static"
	include	"icon_item_dungeon_static"
	include	"icon_item_gameover_static"
	include	"icon_item_jpn_static"
	include	"icon_item_nes_static"


	include	"item_name_static"
	include	"map_name_static"


 
	include	"do_action_static"


 
	include	"message_static"
	include	"message_texture_static"







	include	"nes_font_static"
	include	"message_data_static"
	include	"nes_message_data_static"
	include	"staff_message_data_static"



 
	include	"map_grand_static"
	include	"map_i_static"







	include	"map_48x85_static"

 
	include "code"

	include "zbuffer"
	include "fifobuffer"
	include "yieldbuffer"
	include "dramstackbuffer"
	include "SystemDynamic"
	include "Audioheap"
	include "SystemHeap"




	include "ovl_title"
	include "ovl_select"
	include "ovl_opening"
	include "ovl_file_choose"
	include "ovl_kaleido_scope"
	include "ovl_player_actor"
	include "ovl_map_mark_data"
	include "ovl_En_Test"
 



# 5 "../spec_inc_ovl.inc"
	include "ovl_En_GirlA"
	include "ovl_En_Part"
	include "ovl_En_Light"
	include "ovl_En_Door"
	include "ovl_En_Box"
	include "ovl_En_Poh"
	include "ovl_En_Okuta"
	include "ovl_En_Bom"
	include "ovl_En_Wallmas"
	include "ovl_En_Dodongo"
	include "ovl_En_Firefly"
	include "ovl_En_Horse"
	include "ovl_En_Arrow"
	include "ovl_En_Elf"
	include "ovl_En_Niw"
	include "ovl_En_Tite"
	include "ovl_En_Reeba"
	include "ovl_En_Peehat"
	include "ovl_En_Holl"
	include "ovl_En_Scene_Change"
	include "ovl_En_Zf"
	include "ovl_En_Hata"
	include "ovl_Boss_Dodongo"
	include "ovl_Boss_Goma"
	include "ovl_En_Zl1"
	include "ovl_En_Viewer"
	include "ovl_En_Goma"
	include "ovl_Bg_Pushbox"
	include "ovl_En_Bubble"
	include "ovl_Door_Shutter"
	include "ovl_En_Dodojr"
	include "ovl_En_Bdfire"
	include "ovl_En_Boom"
	include "ovl_En_Torch2"
	include "ovl_En_Bili"
	include "ovl_En_Tp"
	include "ovl_En_St"
	include "ovl_En_Bw"
	include "ovl_En_Eiyer"
	include "ovl_En_River_Sound"
	include "ovl_En_Horse_Normal"
	include "ovl_En_Ossan"
	include "ovl_Bg_Treemouth"
	include "ovl_Bg_Dodoago"
	include "ovl_Bg_Hidan_Dalm"
	include "ovl_Bg_Hidan_Hrock"
	include "ovl_En_Horse_Ganon"
	include "ovl_Bg_Hidan_Rock"
	include "ovl_Bg_Hidan_Rsekizou"
	include "ovl_Bg_Hidan_Sekizou"
	include "ovl_Bg_Hidan_Sima"
	include "ovl_Bg_Hidan_Syoku"
	include "ovl_En_Xc"
	include "ovl_Bg_Hidan_Curtain"
	include "ovl_Bg_Spot00_Hanebasi"
	include "ovl_En_Mb"
	include "ovl_En_Bombf"
	include "ovl_Bg_Hidan_Firewall"
	include "ovl_Bg_Dy_Yoseizo"
	include "ovl_En_Zl2"
	include "ovl_Bg_Hidan_Fslift"
	include "ovl_En_OE2"
	include "ovl_Bg_Ydan_Hasi"
	include "ovl_Bg_Ydan_Maruta"
	include "ovl_Boss_Ganondrof"
	include "ovl_En_Am"
	include "ovl_En_Dekubaba"
	include "ovl_En_M_Fire1"
	include "ovl_En_M_Thunder"
	include "ovl_Bg_Ddan_Jd"
	include "ovl_Bg_Breakwall"
	include "ovl_En_Jj"
	include "ovl_En_Horse_Zelda"
	include "ovl_Bg_Ddan_Kd"
	include "ovl_Door_Warp1"
	include "ovl_Obj_Syokudai"
	include "ovl_Item_B_Heart"
	include "ovl_En_Dekunuts"
	include "ovl_Bg_Menkuri_Kaiten"
	include "ovl_Bg_Menkuri_Eye"
	include "ovl_En_Vali"
	include "ovl_Bg_Mizu_Movebg"
	include "ovl_Bg_Mizu_Water"
	include "ovl_Arms_Hook"
	include "ovl_En_fHG"
	include "ovl_Bg_Mori_Hineri"
	include "ovl_En_Bb"
	include "ovl_Bg_Toki_Hikari"
	include "ovl_En_Yukabyun"
	include "ovl_Bg_Toki_Swd"
	include "ovl_En_Fhg_Fire"
	include "ovl_Bg_Mjin"
	include "ovl_Bg_Hidan_Kousi"
	include "ovl_Door_Toki"
	include "ovl_Bg_Hidan_Hamstep"
	include "ovl_En_Bird"
	include "ovl_En_Wood02"
	include "ovl_En_Lightbox"
	include "ovl_En_Pu_box"
	include "ovl_En_Trap"
	include "ovl_En_Arow_Trap"
	include "ovl_En_Vase"
	include "ovl_En_Ta"
	include "ovl_En_Tk"
	include "ovl_Bg_Mori_Bigst"
	include "ovl_Bg_Mori_Elevator"
	include "ovl_Bg_Mori_Kaitenkabe"
	include "ovl_Bg_Mori_Rakkatenjo"
	include "ovl_En_Vm"
	include "ovl_Demo_Effect"
	include "ovl_Demo_Kankyo"
	include "ovl_Bg_Hidan_Fwbig"
	include "ovl_En_Floormas"
	include "ovl_En_Heishi1"
	include "ovl_En_Rd"
	include "ovl_En_Po_Sisters"
	include "ovl_Bg_Heavy_Block"
	include "ovl_Bg_Po_Event"
	include "ovl_Obj_Mure"
	include "ovl_En_Sw"
	include "ovl_Boss_Fd"
	include "ovl_Object_Kankyo"
	include "ovl_En_Du"
	include "ovl_En_Fd"
	include "ovl_En_Horse_Link_Child"
	include "ovl_Door_Ana"
	include "ovl_Bg_Spot02_Objects"
	include "ovl_Bg_Haka"
	include "ovl_Magic_Wind"
	include "ovl_Magic_Fire"
	include "ovl_En_Ru1"
	include "ovl_Boss_Fd2"
	include "ovl_En_Fd_Fire"
	include "ovl_En_Dh"
	include "ovl_En_Dha"
	include "ovl_En_Rl"
	include "ovl_En_Encount1"
	include "ovl_Demo_Du"
	include "ovl_Demo_Im"
	include "ovl_Demo_Tre_Lgt"
	include "ovl_En_Fw"
	include "ovl_Bg_Vb_Sima"
	include "ovl_En_Vb_Ball"
	include "ovl_Bg_Haka_Megane"
	include "ovl_Bg_Haka_MeganeBG"
	include "ovl_Bg_Haka_Ship"
	include "ovl_Bg_Haka_Sgami"
	include "ovl_En_Heishi2"
	include "ovl_En_Encount2"
	include "ovl_En_Fire_Rock"
	include "ovl_En_Brob"
	include "ovl_Mir_Ray"
	include "ovl_Bg_Spot09_Obj"
	include "ovl_Bg_Spot18_Obj"
	include "ovl_Boss_Va"
	include "ovl_Bg_Haka_Tubo"
	include "ovl_Bg_Haka_Trap"
	include "ovl_Bg_Haka_Huta"
	include "ovl_Bg_Haka_Zou"
	include "ovl_Bg_Spot17_Funen"
	include "ovl_En_Syateki_Itm"
	include "ovl_En_Syateki_Man"
	include "ovl_En_Tana"
	include "ovl_En_Nb"
	include "ovl_Boss_Mo"
	include "ovl_En_Sb"
	include "ovl_En_Bigokuta"
	include "ovl_En_Karebaba"
	include "ovl_Bg_Bdan_Objects"
	include "ovl_Demo_Sa"
	include "ovl_Demo_Go"
	include "ovl_En_In"
	include "ovl_En_Tr"
	include "ovl_Bg_Spot16_Bombstone"
	include "ovl_Bg_Hidan_Kowarerukabe"
	include "ovl_Bg_Bombwall"
	include "ovl_En_Ru2"
	include "ovl_Obj_Dekujr"
	include "ovl_Bg_Mizu_Uzu"
	include "ovl_Bg_Spot06_Objects"
	include "ovl_Bg_Ice_Objects"
	include "ovl_Bg_Haka_Water"
	include "ovl_En_Ma2"
	include "ovl_En_Bom_Chu"
	include "ovl_En_Horse_Game_Check"
	include "ovl_Boss_Tw"
	include "ovl_En_Rr"
	include "ovl_En_Ba"
	include "ovl_En_Bx"
	include "ovl_En_Anubice"
	include "ovl_En_Anubice_Fire"
	include "ovl_Bg_Mori_Hashigo"
	include "ovl_Bg_Mori_Hashira4"
	include "ovl_Bg_Mori_Idomizu"
	include "ovl_Bg_Spot16_Doughnut"
	include "ovl_Bg_Bdan_Switch"
	include "ovl_En_Ma1"
	include "ovl_Boss_Ganon"
	include "ovl_Boss_Sst"
	include "ovl_En_Ny"
	include "ovl_En_Fr"
	include "ovl_Item_Shield"
	include "ovl_Bg_Ice_Shelter"
	include "ovl_En_Ice_Hono"
	include "ovl_Item_Ocarina"
	include "ovl_Magic_Dark"
	include "ovl_Demo_6K"
	include "ovl_En_Anubice_Tag"
	include "ovl_Bg_Haka_Gate"
	include "ovl_Bg_Spot15_Saku"
	include "ovl_Bg_Jya_Goroiwa"
	include "ovl_Bg_Jya_Zurerukabe"
	include "ovl_Bg_Jya_Cobra"
	include "ovl_Bg_Jya_Kanaami"
	include "ovl_Fishing"
	include "ovl_Obj_Oshihiki"
	include "ovl_Bg_Gate_Shutter"
	include "ovl_Eff_Dust"
	include "ovl_Bg_Spot01_Fusya"
	include "ovl_Bg_Spot01_Idohashira"
	include "ovl_Bg_Spot01_Idomizu"
	include "ovl_Bg_Po_Syokudai"
	include "ovl_Bg_Ganon_Otyuka"
	include "ovl_Bg_Spot15_Rrbox"
	include "ovl_Bg_Umajump"
	include "ovl_En_Insect"
	include "ovl_En_Butte"
	include "ovl_En_Fish"
	include "ovl_Bg_Spot08_Iceblock"
	include "ovl_Item_Etcetera"
	include "ovl_Arrow_Fire"
	include "ovl_Arrow_Ice"
	include "ovl_Arrow_Light"
	include "ovl_Obj_Kibako"
	include "ovl_Obj_Tsubo"
	include "ovl_En_Wonder_Item"
	include "ovl_En_Ik"
	include "ovl_Demo_Ik"
	include "ovl_En_Skj"
	include "ovl_En_Skjneedle"
	include "ovl_En_G_Switch"
	include "ovl_Demo_Ext"
	include "ovl_Demo_Shd"
	include "ovl_En_Dns"
	include "ovl_Elf_Msg"
	include "ovl_En_Honotrap"
	include "ovl_En_Tubo_Trap"
	include "ovl_Obj_Ice_Poly"
	include "ovl_Bg_Spot03_Taki"
	include "ovl_Bg_Spot07_Taki"
	include "ovl_En_Fz"
	include "ovl_En_Po_Relay"
	include "ovl_Bg_Relay_Objects"
	include "ovl_En_Diving_Game"
	include "ovl_En_Kusa"
	include "ovl_Obj_Bean"
	include "ovl_Obj_Bombiwa"
	include "ovl_Obj_Switch"
	include "ovl_Obj_Elevator"
	include "ovl_Obj_Lift"
	include "ovl_Obj_Hsblock"
	include "ovl_En_Okarina_Tag"
	include "ovl_En_Yabusame_Mark"
	include "ovl_En_Goroiwa"
	include "ovl_En_Ex_Ruppy"
	include "ovl_En_Toryo"
	include "ovl_En_Daiku"
	include "ovl_En_Nwc"
	include "ovl_En_Blkobj"
	include "ovl_Item_Inbox"
	include "ovl_En_Ge1"
	include "ovl_Obj_Blockstop"
	include "ovl_En_Sda"
	include "ovl_En_Clear_Tag"
	include "ovl_En_Niw_Lady"
	include "ovl_En_Gm"
	include "ovl_En_Ms"
	include "ovl_En_Hs"
	include "ovl_Bg_Ingate"
	include "ovl_En_Kanban"
	include "ovl_En_Heishi3"
	include "ovl_En_Syateki_Niw"
	include "ovl_En_Attack_Niw"
	include "ovl_Bg_Spot01_Idosoko"
	include "ovl_En_Sa"
	include "ovl_En_Wonder_Talk"
	include "ovl_Bg_Gjyo_Bridge"
	include "ovl_En_Ds"
	include "ovl_En_Mk"
	include "ovl_En_Bom_Bowl_Man"
	include "ovl_En_Bom_Bowl_Pit"
	include "ovl_En_Owl"
	include "ovl_En_Ishi"
	include "ovl_Obj_Hana"
	include "ovl_Obj_Lightswitch"
	include "ovl_Obj_Mure2"
	include "ovl_En_Go"
	include "ovl_En_Fu"
	include "ovl_En_Changer"
	include "ovl_Bg_Jya_Megami"
	include "ovl_Bg_Jya_Lift"
	include "ovl_Bg_Jya_Bigmirror"
	include "ovl_Bg_Jya_Bombchuiwa"
	include "ovl_Bg_Jya_Amishutter"
	include "ovl_Bg_Jya_Bombiwa"
	include "ovl_Bg_Spot18_Basket"
	include "ovl_En_Ganon_Organ"
	include "ovl_En_Siofuki"
	include "ovl_En_Stream"
	include "ovl_En_Mm"
	include "ovl_En_Ko"
	include "ovl_En_Kz"
	include "ovl_En_Weather_Tag"
	include "ovl_Bg_Sst_Floor"
	include "ovl_En_Ani"
	include "ovl_En_Ex_Item"
	include "ovl_Bg_Jya_Ironobj"
	include "ovl_En_Js"
	include "ovl_En_Jsjutan"
	include "ovl_En_Cs"
	include "ovl_En_Md"
	include "ovl_En_Hy"
	include "ovl_En_Ganon_Mant"
	include "ovl_En_Okarina_Effect"
	include "ovl_En_Mag"
	include "ovl_Door_Gerudo"
	include "ovl_Elf_Msg2"
	include "ovl_Demo_Gt"
	include "ovl_En_Po_Field"
	include "ovl_Efc_Erupc"
	include "ovl_Bg_Zg"
	include "ovl_En_Heishi4"
	include "ovl_En_Zl3"
	include "ovl_Boss_Ganon2"
	include "ovl_En_Kakasi"
	include "ovl_En_Takara_Man"
	include "ovl_Obj_Makeoshihiki"
	include "ovl_Oceff_Spot"
	include "ovl_End_Title"
	include "ovl_En_Torch"
	include "ovl_Demo_Ec"
	include "ovl_Shot_Sun"
	include "ovl_En_Dy_Extra"
	include "ovl_En_Wonder_Talk2"
	include "ovl_En_Ge2"
	include "ovl_Obj_Roomtimer"
	include "ovl_En_Ssh"
	include "ovl_En_Sth"
	include "ovl_Oceff_Wipe"
	include "ovl_Effect_Ss_Dust"
	include "ovl_Effect_Ss_KiraKira"
	include "ovl_Effect_Ss_Bomb"
	include "ovl_Effect_Ss_Bomb2"
	include "ovl_Effect_Ss_Blast"
	include "ovl_Effect_Ss_G_Spk"
	include "ovl_Effect_Ss_D_Fire"
	include "ovl_Effect_Ss_Bubble"
	include "ovl_Effect_Ss_G_Ripple"
	include "ovl_Effect_Ss_G_Splash"
	include "ovl_Effect_Ss_G_Magma"
	include "ovl_Effect_Ss_G_Fire"
	include "ovl_Effect_Ss_Lightning"
	include "ovl_Effect_Ss_Dt_Bubble"
	include "ovl_Effect_Ss_Hahen"
	include "ovl_Effect_Ss_Stick"
	include "ovl_Effect_Ss_Sibuki"
	include "ovl_Effect_Ss_Sibuki2"
	include "ovl_Effect_Ss_G_Magma2"
	include "ovl_Effect_Ss_Stone1"
	include "ovl_Effect_Ss_HitMark"
	include "ovl_Effect_Ss_Fhg_Flash"
	include "ovl_Effect_Ss_K_Fire"
	include "ovl_Effect_Ss_Solder_Srch_Ball"
	include "ovl_Effect_Ss_Kakera"
	include "ovl_Effect_Ss_Ice_Piece"
	include "ovl_Effect_Ss_En_Ice"
	include "ovl_Effect_Ss_Fire_Tail"
	include "ovl_Effect_Ss_En_Fire"
	include "ovl_Effect_Ss_Extra"
	include "ovl_Effect_Ss_Fcircle"
	include "ovl_Effect_Ss_Dead_Db"
	include "ovl_Effect_Ss_Dead_Dd"
	include "ovl_Effect_Ss_Dead_Ds"
	include "ovl_Effect_Ss_Dead_Sound"
	include "ovl_Oceff_Storm"
	include "ovl_En_Weiyer"
	include "ovl_Bg_Spot05_Soko"
	include "ovl_Bg_Jya_1flift"
	include "ovl_Bg_Jya_Haheniron"
	include "ovl_Bg_Spot12_Gate"
	include "ovl_Bg_Spot12_Saku"
	include "ovl_En_Hintnuts"
	include "ovl_En_Nutsball"
	include "ovl_Bg_Spot00_Break"
	include "ovl_En_Shopnuts"
	include "ovl_En_It"
	include "ovl_En_GeldB"
	include "ovl_Oceff_Wipe2"
	include "ovl_Oceff_Wipe3"
	include "ovl_En_Niw_Girl"
	include "ovl_En_Dog"
	include "ovl_En_Si"
	include "ovl_Bg_Spot01_Objects2"
	include "ovl_Obj_Comb"
	include "ovl_Bg_Spot11_Bakudankabe"
	include "ovl_Obj_Kibako2"
	include "ovl_En_Dnt_Demo"
	include "ovl_En_Dnt_Jiji"
	include "ovl_En_Dnt_Nomal"
	include "ovl_En_Guest"
	include "ovl_Bg_Bom_Guard"
	include "ovl_En_Hs2"
	include "ovl_Demo_Kekkai"
	include "ovl_Bg_Spot08_Bakudankabe"
	include "ovl_Bg_Spot17_Bakudankabe"
	include "ovl_Obj_Mure3"
	include "ovl_En_Tg"
	include "ovl_En_Mu"
	include "ovl_En_Go2"
	include "ovl_En_Wf"
	include "ovl_En_Skb"
	include "ovl_Demo_Gj"
	include "ovl_Demo_Geff"
	include "ovl_Bg_Gnd_Firemeiro"
	include "ovl_Bg_Gnd_Darkmeiro"
	include "ovl_Bg_Gnd_Soulmeiro"
	include "ovl_Bg_Gnd_Nisekabe"
	include "ovl_Bg_Gnd_Iceblock"
	include "ovl_Bg_Ydan_Sp"
	include "ovl_En_Gb"
	include "ovl_En_Gs"
	include "ovl_Bg_Mizu_Bwall"
	include "ovl_Bg_Mizu_Shutter"
	include "ovl_En_Daiku_Kakariko"
	include "ovl_Bg_Bowl_Wall"
	include "ovl_En_Wall_Tubo"
	include "ovl_En_Po_Desert"
	include "ovl_En_Crow"
	include "ovl_Door_Killer"
	include "ovl_Bg_Spot11_Oasis"
	include "ovl_Bg_Spot18_Futa"
	include "ovl_Bg_Spot18_Shutter"
	include "ovl_En_Ma3"
	include "ovl_En_Cow"
	include "ovl_Bg_Ice_Turara"
	include "ovl_Bg_Ice_Shutter"
	include "ovl_En_Kakasi2"
	include "ovl_En_Kakasi3"
	include "ovl_Oceff_Wipe4"
	include "ovl_En_Eg"
	include "ovl_Bg_Menkuri_Nisekabe"
	include "ovl_En_Zo"
	include "ovl_Effect_Ss_Ice_Smoke"
	include "ovl_Obj_Makekinsuta"
	include "ovl_En_Ge3"
	include "ovl_Obj_Timeblock"
	include "ovl_Obj_Hamishi"
	include "ovl_En_Zl4"
	include "ovl_En_Mm2"
	include "ovl_Bg_Jya_Block"
	include "ovl_Obj_Warp2block"
# 1250 "../spec"

 

# 1 "../spec.segment"
 




























































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































# 3088 "../spec.segment"






	include "rcp_cfb"
	include "rcp_zb"

	include "gameplay_keep"
	include "gameplay_field_keep"
	include "gameplay_dangeon_keep"

	include "gameplay_object_exchange_static"
	include "object_link_boy"
	include "object_link_child"
	include "object_box"
	include "object_human"
	include "object_okuta"
	include "object_poh"
	include "object_wallmaster"
	include "object_dy_obj"
	include "object_firefly"
	include "object_dodongo"
	include "object_fire"
	include "object_niw"
	include "object_tite"
	include "object_reeba"
	include "object_peehat"
	include "object_kingdodongo"
	include "object_horse"
	include "object_zf"
	include "object_goma"
	include "object_zl1"
	include "object_gol"
	include "object_bubble"
	include "object_dodojr"
	include "object_torch2"
	include "object_bl"
	include "object_tp"
	include "object_oA1"
	include "object_st"
	include "object_bw"
	include "object_ei"
	include "object_horse_normal"
	include "object_oB1"
	include "object_o_anime"
	include "object_spot04_objects"
	include "object_ddan_objects"
	include "object_hidan_objects"
	include "object_horse_ganon"
	include "object_oA2"
	include "object_spot00_objects"
	include "object_mb"
	include "object_bombf"
	include "object_sk2"
	include "object_oE1"
	include "object_oE_anime"
	include "object_oE2"
	include "object_ydan_objects"
	include "object_gnd"
	include "object_am"
	include "object_dekubaba"
	include "object_oA3"
	include "object_oA4"
	include "object_oA5"
	include "object_oA6"
	include "object_oA7"
	include "object_jj"
	include "object_oA8"
	include "object_oA9"
	include "object_oB2"
	include "object_oB3"
	include "object_oB4"
        include "object_horse_zelda"	
        include "object_opening_demo1"	
        include "object_warp1"	
        include "object_b_heart"
	include "object_dekunuts"
	include "object_oE3"
	include "object_oE4"
	include "object_menkuri_objects"
	include "object_oE5"
	include "object_oE6"
	include "object_oE7"
	include "object_oE8"
	include "object_oE9"
	include "object_oE10"
	include "object_oE11"
	include "object_oE12"
	include "object_vali"
	include "object_oA10"
	include "object_oA11"
	include "object_mizu_objects"
	include "object_fhg"
	include "object_ossan"
	include "object_mori_hineri1"
	include "object_Bb"
	include "object_toki_objects"
	include "object_yukabyun"
	include "object_zl2"
	include "object_mjin"
	include "object_mjin_flash"
	include "object_mjin_dark"
	include "object_mjin_flame"
	include "object_mjin_ice"
	include "object_mjin_soul"
	include "object_mjin_wind"
	include "object_mjin_oka"
	include "object_haka_objects"
	include "object_spot06_objects"
	include "object_ice_objects"
	include "object_relay_objects"
	include "object_mori_hineri1a"
	include "object_mori_hineri2"
	include "object_mori_hineri2a"
	include "object_mori_objects"
	include "object_mori_tex"
	include "object_spot08_obj"
        include "object_warp2"	
        include "object_hata"	
        include "object_bird"	
        include "object_wood02"	
        include "object_lightbox"
        include "object_pu_box"
        include "object_trap"
        include "object_vase"
        include "object_im"
        include "object_ta"
        include "object_tk"
        include "object_xc"
        include "object_vm"
        include "object_bv"
	include "object_hakach_objects"
	include "object_efc_crystal_light"
	include "object_efc_fire_ball"
	include "object_efc_flash"
	include "object_efc_lgt_shower"
	include "object_efc_star_field"
	include "object_god_lgt"
	include "object_light_ring"
	include "object_triforce_spot"
	include "object_medal"
	include "object_bdan_objects"
        include "object_sd"
        include "object_rd"
	include "object_po_sisters"
	include "object_heavy_object"
	include "object_gndd"
	include "object_fd"
	include "object_du"
	include "object_fw"
        include "object_horse_link_child"
	include "object_spot02_objects"
	include "object_haka"
	include "object_ru1"
	include "object_syokudai"
	include "object_fd2"
	include "object_dh"
	include "object_rl"
	include "object_efc_tw"
	include "object_demo_tre_lgt"
	include "object_gi_key"
	include "object_mir_ray"
	include "object_brob"
	include "object_gi_jewel"
	include "object_spot09_obj"
	include "object_spot18_obj"
	include "object_bdoor"
	include "object_spot17_obj"
	include "object_shop_dungen"
	include "object_nb"
	include "object_mo"
	include "object_sb"
	include "object_gi_melody"
	include "object_gi_heart"
	include "object_gi_compass"
	include "object_gi_bosskey"
	include "object_gi_medal"
	include "object_gi_nuts"
	include "object_sa"
	include "object_gi_hearts"
	include "object_gi_arrowcase"
	include "object_gi_bombpouch"
        include "object_in"
        include "object_tr"
	include "object_spot16_obj"
	include "object_oE1s"
	include "object_oE4s"
	include "object_os_anime"
	include "object_gi_bottle"
	include "object_gi_stick"
	include "object_gi_map"
	include "object_oF1d_map"
	include "object_ru2"
	include "object_gi_shield_1"
	include "object_dekujr"
	include "object_gi_magicpot"
	include "object_gi_bomb_1"
	include "object_oF1s"
        include "object_ma2"
	include "object_gi_purse"
	include "object_hni"
	include "object_tw"
	include "object_rr"
	include "object_bxa"
	include "object_anubice"
	include "object_gi_gerudo"
	include "object_gi_arrow"
	include "object_gi_bomb_2"
	include "object_gi_egg"
	include "object_gi_scale"
	include "object_gi_shield_2"
	include "object_gi_hookshot"
	include "object_gi_ocarina"
	include "object_gi_milk"
        include "object_ma1"
        include "object_ganon"
        include "object_sst"
        include "object_go2"
        include "object_ny"
        include "object_fr"
        include "object_gi_pachinko"
        include "object_gi_boomerang"
        include "object_gi_bow"
        include "object_gi_glasses"
        include "object_gi_liquid"
	include "object_ani"
	include "object_demo_6k"
        include "object_gi_shield_3"
        include "object_gi_letter"
	include "object_spot15_obj"
	include "object_jya_obj"
        include "object_gi_clothes"
        include "object_gi_bean"
        include "object_gi_fish"
        include "object_gi_saw"
        include "object_gi_hammer"
        include "object_gi_grass"
        include "object_gi_longsword"
	include "object_spot01_objects"
	include "object_gate"
	include "object_md"
	include "object_km1"
	include "object_kw1"
	include "object_zo"
	include "object_kz"
	include "object_umajump"
	include "object_masterkokiri"
	include "object_masterkokirihead"
	include "object_mastergolon"
	include "object_masterzoora"
	include "object_aob"
	include "object_ik"
	include "object_ahg"
	include "object_cne"
        include "object_gi_niwatori"
        include "object_skj"
        include "object_gi_bottle_letter"
	include "object_bji"
	include "object_bba"
        include "object_gi_ocarina_0"
        include "object_ds"
	include "object_ane"
	include "object_boj"
	include "object_spot03_object"
	include "object_spot07_object"
	include "object_fz"
	include "object_bob"
	include "object_ge1"
	include "object_yabusame_point"
	include "object_gi_boots_2"
	include "object_gi_seed"
	include "object_gnd_magic"
	include "object_d_elevator"
	include "object_d_hsblock"
	include "object_d_lift"
	include "object_mamenoki"
	include "object_goroiwa"



	include "object_toryo"
	include "object_daiku"
	include "object_nwc"
	include "object_blkobj"
	include "object_gm"
	include "object_ms"
	include "object_hs"
	include "object_ingate"
	include "object_lightswitch"
	include "object_kusa"
	include "object_tsubo"
	include "object_gi_gloves"
	include "object_gi_coin"
	include "object_kanban"
	include "object_gjyo_objects"
	include "object_owl"
	include "object_mk"
        include "object_fu"
        include "object_gi_ki_tan_mask"
        include "object_gi_redead_mask"
        include "object_gi_skj_mask"
        include "object_gi_rabit_mask"
        include "object_gi_truth_mask"
	include "object_ganon_objects"
	include "object_siofuki"
	include "object_stream"
	include "object_mm"
	include "object_fa"
	include "object_os"
	include "object_gi_eye_lotion"
	include "object_gi_powder"
	include "object_gi_mushroom"
	include "object_gi_ticketstone"
	include "object_gi_brokensword"
	include "object_js"
	include "object_cs"
	include "object_gi_prescription"
	include "object_gi_bracelet"
	include "object_gi_soldout"
	include "object_gi_frog"
	include "object_mag"
	include "object_door_gerudo"
	include "object_gt"
	include "object_efc_erupc"
	include "object_zl2_anime1"
	include "object_zl2_anime2"
	include "object_gi_golonmask"
	include "object_gi_zoramask"
	include "object_gi_gerudomask"
        include "object_ganon2"
        include "object_ka"
        include "object_ts"
        include "object_zg"
        include "object_gi_hoverboots"
        include "object_gi_m_arrow"
        include "object_ds2"
        include "object_ec"
        include "object_fish"
        include "object_gi_sutaru"
        include "object_gi_goddess"
        include "object_ssh"
	include "object_bigokuta"
	include "object_bg"
	include "object_spot05_objects"
	include "object_spot12_obj"
	include "object_bombiwa"
	include "object_hintnuts"
	include "object_rs"
	include "object_spot00_break"
	include "object_gla"
	include "object_shopnuts"
	include "object_geldb"
	include "object_gr"
	include "object_dog"
	include "object_jya_iron"
	include "object_jya_door"
	include "object_spot01_objects2"
	include "object_spot11_obj"
	include "object_kibako2"
	include "object_dns"
	include "object_dnk"
        include "object_gi_fire"
        include "object_gi_insect"
        include "object_gi_butterfly"
        include "object_gi_ghost"
        include "object_gi_soul"
        include "object_bowl"
	include "object_po_field"
	include "object_demo_kekkai"
	include "object_efc_doughnut"
        include "object_gi_dekupouch"
        include "object_ganon_anime1"
        include "object_ganon_anime2"
        include "object_ganon_anime3"
        include "object_gi_rupy"
        include "object_spot01_matoya"
        include "object_spot01_matoyab"
	include "object_po_composer"
	include "object_mu"
	include "object_wf"
	include "object_skb"
	include "object_gj"
	include "object_geff"
	include "object_haka_door"
	include "object_gs"
	include "object_ps"
	include "object_bwall"
	include "object_crow"
	include "object_cow"
	include "object_cob"
	include "object_gi_sword_1"
	include "object_door_killer"
	include "object_ouke_haka" 
	include "object_timeblock" 
	include "object_zl4"

        include "g_pn_01"
        include "g_pn_02"
        include "g_pn_03"
        include "g_pn_04"
        include "g_pn_05"
        include "g_pn_06"
        include "g_pn_07"
        include "g_pn_08"
        include "g_pn_09"
        include "g_pn_10"
        include "g_pn_11"
        include "g_pn_12"
        include "g_pn_13"
        include "g_pn_14"
        include "g_pn_15"
        include "g_pn_16"
        include "g_pn_17"
        include "g_pn_18"
        include "g_pn_19"
        include "g_pn_20"
        include "g_pn_21"
        include "g_pn_22"
        include "g_pn_23"
        include "g_pn_24"
        include "g_pn_25"
        include "g_pn_26"
        include "g_pn_27"
        include "g_pn_28"
        include "g_pn_29"
        include "g_pn_30"
        include "g_pn_31"
        include "g_pn_32"
        include "g_pn_33"
        include "g_pn_34"
        include "g_pn_35"
        include "g_pn_36"
        include "g_pn_37"
        include "g_pn_38"
        include "g_pn_39"
        include "g_pn_40"
        include "g_pn_41"
        include "g_pn_42"
        include "g_pn_43"
        include "g_pn_44"
        include "g_pn_45"
        include "g_pn_46"
        include "g_pn_47"
        include "g_pn_48"
        include "g_pn_49"
        include "g_pn_50"
        include "g_pn_51"
        include "g_pn_52"
        include "g_pn_53"
        include "g_pn_54"
        include "g_pn_55"
        include "g_pn_56"
        include "g_pn_57"

	include "z_select_static"



 
	include "nintendo_rogo_static"
 
	include "title_static"





 
	include "parameter_static"


 
	 
	include "vr_fine0_static"
	include "vr_fine0_pal_static"
	include "vr_fine1_static"
	include "vr_fine1_pal_static"
	include "vr_fine2_static"
	include "vr_fine2_pal_static"
	include "vr_fine3_static"
	include "vr_fine3_pal_static"
	 
	include "vr_cloud0_static"
	include "vr_cloud0_pal_static"
	include "vr_cloud1_static"
	include "vr_cloud1_pal_static"
	include "vr_cloud2_static"
	include "vr_cloud2_pal_static"
	include "vr_cloud3_static"
	include "vr_cloud3_pal_static"










	 
	include "vr_holy0_static"
	include "vr_holy0_pal_static"
	include "vr_holy1_static"
	include "vr_holy1_pal_static"

 
	 
	include	"vr_MDVR_static"
	include	"vr_MDVR_pal_static"
	 
	include	"vr_MNVR_static"
	include	"vr_MNVR_pal_static"
	 
	include	"vr_RUVR_static"
	include	"vr_RUVR_pal_static"















	 
	include "vr_LHVR_static"
	include "vr_LHVR_pal_static"
	 
	include "vr_KHVR_static"
	include "vr_KHVR_pal_static"





	 
	include "vr_K3VR_static"
	include "vr_K3VR_pal_static"
	 
	include "vr_K4VR_static"
	include "vr_K4VR_pal_static"
	 
	include "vr_K5VR_static"
	include "vr_K5VR_pal_static"
	 
	include "vr_SP1a_static"
	include "vr_SP1a_pal_static"
	 
	include "vr_MLVR_static"
	include "vr_MLVR_pal_static"
	 
	include "vr_KKRVR_static"
	include "vr_KKRVR_pal_static"





	 
	include "vr_KR3VR_static"
	include "vr_KR3VR_pal_static"
	 
	include "vr_IPVR_static"
	include "vr_IPVR_pal_static"
	 
	include "vr_KSVR_static"
	include "vr_KSVR_pal_static"





	 
	include "vr_GLVR_static"
	include "vr_GLVR_pal_static"
	 
	include "vr_ZRVR_static"
	include "vr_ZRVR_pal_static"





	 
	include "vr_DGVR_static"
	include "vr_DGVR_pal_static"
	 
	include "vr_ALVR_static"
	include "vr_ALVR_pal_static"
	 
	include "vr_NSVR_static"
	include "vr_NSVR_pal_static"
	 
	include "vr_LBVR_static"
	include "vr_LBVR_pal_static"
	 
	include "vr_TTVR_static"
	include "vr_TTVR_pal_static"
	 
	include "vr_FCVR_static"
	include "vr_FCVR_pal_static"












 


	include "elf_message_field"
	include "elf_message_ydan"









































	include "spot00_scene"
	include "spot00_room_0"

	include "spot01_scene"
	include "spot01_room_0"

	include "spot02_scene"
	include "spot02_room_0"
	include "spot02_room_1"

	include "spot03_scene"
	include "spot03_room_0"
	include "spot03_room_1"

	include "spot04_scene"
	include "spot04_room_0"
	include "spot04_room_1"
	include "spot04_room_2"

	include "spot05_scene"
	include "spot05_room_0"

	include "spot06_scene"
	include "spot06_room_0"

	include "spot07_scene"
	include "spot07_room_0"
	include "spot07_room_1"

	include "spot08_scene"
	include "spot08_room_0"

	include "spot09_scene"
	include "spot09_room_0"

	include "spot10_scene"
	include "spot10_room_0"
	include "spot10_room_1"
	include "spot10_room_2"
	include "spot10_room_3"
	include "spot10_room_4"
	include "spot10_room_5"
	include "spot10_room_6"
	include "spot10_room_7"
	include "spot10_room_8"
	include "spot10_room_9"

	include "spot11_scene"
	include "spot11_room_0"

	include "spot12_scene"
	include "spot12_room_0"
	include "spot12_room_1"

	include "spot13_scene"
	include "spot13_room_0"
	include "spot13_room_1"

	include "spot15_scene"
	include "spot15_room_0"

	include "spot16_scene"
	include "spot16_room_0"

	include "spot17_scene"
	include "spot17_room_0"
	include "spot17_room_1"

	include "spot18_scene"
	include "spot18_room_0"
	include "spot18_room_1"
	include "spot18_room_2"
	include "spot18_room_3"









	include "ydan_scene"
	include "ydan_room_0"
	include "ydan_room_1"
	include "ydan_room_2"
	include "ydan_room_3"
	include "ydan_room_4"
	include "ydan_room_5"
	include "ydan_room_6"
	include "ydan_room_7"
	include "ydan_room_8"
	include "ydan_room_9"
	include "ydan_room_10"
	include "ydan_room_11"

	include "ddan_scene"
	include "ddan_room_0"
	include "ddan_room_1"
	include "ddan_room_2"
	include "ddan_room_3"
	include "ddan_room_4"
	include "ddan_room_5"
	include "ddan_room_6"
	include "ddan_room_7"
	include "ddan_room_8"
	include "ddan_room_9"
	include "ddan_room_10"
	include "ddan_room_11"
	include "ddan_room_12"
	include "ddan_room_13"
	include "ddan_room_14"
	include "ddan_room_15"
	include "ddan_room_16"

	include "bdan_scene"
	include "bdan_room_0"
	include "bdan_room_1"
	include "bdan_room_2"
	include "bdan_room_3"
	include "bdan_room_4"
	include "bdan_room_5"
	include "bdan_room_6"
	include "bdan_room_7"
	include "bdan_room_8"
	include "bdan_room_9"
	include "bdan_room_10"
	include "bdan_room_11"
	include "bdan_room_12"
	include "bdan_room_13"
	include "bdan_room_14"
	include "bdan_room_15"

	include "Bmori1_scene"
	include "Bmori1_room_0"
	include "Bmori1_room_1"
	include "Bmori1_room_2"
	include "Bmori1_room_3"
	include "Bmori1_room_4"
	include "Bmori1_room_5"
	include "Bmori1_room_6"
	include "Bmori1_room_7"
	include "Bmori1_room_8"
	include "Bmori1_room_9"
	include "Bmori1_room_10"
	include "Bmori1_room_11"
	include "Bmori1_room_12"
	include "Bmori1_room_13"
	include "Bmori1_room_14"
	include "Bmori1_room_15"
	include "Bmori1_room_16"
	include "Bmori1_room_17"
	include "Bmori1_room_18"
	include "Bmori1_room_19"
	include "Bmori1_room_20"
	include "Bmori1_room_21"
	include "Bmori1_room_22"

	include "HIDAN_scene"
	include "HIDAN_room_0"
	include "HIDAN_room_1"
	include "HIDAN_room_2"
	include "HIDAN_room_3"
	include "HIDAN_room_4"
	include "HIDAN_room_5"
	include "HIDAN_room_6"
	include "HIDAN_room_7"
	include "HIDAN_room_8"
	include "HIDAN_room_9"
	include "HIDAN_room_10"
	include "HIDAN_room_11"
	include "HIDAN_room_12"
	include "HIDAN_room_13"
	include "HIDAN_room_14"
	include "HIDAN_room_15"
	include "HIDAN_room_16"
	include "HIDAN_room_17"
	include "HIDAN_room_18"
	include "HIDAN_room_19"
	include "HIDAN_room_20"
	include "HIDAN_room_21"
	include "HIDAN_room_22"
	include "HIDAN_room_23"
	include "HIDAN_room_24"
	include "HIDAN_room_25"
	include "HIDAN_room_26"

	include "MIZUsin_scene"
	include "MIZUsin_room_0"
	include "MIZUsin_room_1"
	include "MIZUsin_room_2"
	include "MIZUsin_room_3"
	include "MIZUsin_room_4"
	include "MIZUsin_room_5"
	include "MIZUsin_room_6"
	include "MIZUsin_room_7"
	include "MIZUsin_room_8"
	include "MIZUsin_room_9"
	include "MIZUsin_room_10"
	include "MIZUsin_room_11"
	include "MIZUsin_room_12"
	include "MIZUsin_room_13"
	include "MIZUsin_room_14"
	include "MIZUsin_room_15"
	include "MIZUsin_room_16"
	include "MIZUsin_room_17"
	include "MIZUsin_room_18"
	include "MIZUsin_room_19"
	include "MIZUsin_room_20"
	include "MIZUsin_room_21"
	include "MIZUsin_room_22"

	include "jyasinzou_scene"
	include "jyasinzou_room_0"
	include "jyasinzou_room_1"
	include "jyasinzou_room_2"
	include "jyasinzou_room_3"
	include "jyasinzou_room_4"
	include "jyasinzou_room_5"
	include "jyasinzou_room_6"
	include "jyasinzou_room_7"
	include "jyasinzou_room_8"
	include "jyasinzou_room_9"
	include "jyasinzou_room_10"
	include "jyasinzou_room_11"
	include "jyasinzou_room_12"
	include "jyasinzou_room_13"
	include "jyasinzou_room_14"
	include "jyasinzou_room_15"
	include "jyasinzou_room_16"
	include "jyasinzou_room_17"
	include "jyasinzou_room_18"
	include "jyasinzou_room_19"
	include "jyasinzou_room_20"
	include "jyasinzou_room_21"
	include "jyasinzou_room_22"
	include "jyasinzou_room_23"
	include "jyasinzou_room_24"
	include "jyasinzou_room_25"
	include "jyasinzou_room_26"
	include "jyasinzou_room_27"
	include "jyasinzou_room_28"

	include "HAKAdan_scene"
	include "HAKAdan_room_0"
	include "HAKAdan_room_1"
	include "HAKAdan_room_2"
	include "HAKAdan_room_3"
	include "HAKAdan_room_4"
	include "HAKAdan_room_5"
	include "HAKAdan_room_6"
	include "HAKAdan_room_7"
	include "HAKAdan_room_8"
	include "HAKAdan_room_9"
	include "HAKAdan_room_10"
	include "HAKAdan_room_11"
	include "HAKAdan_room_12"
	include "HAKAdan_room_13"
	include "HAKAdan_room_14"
	include "HAKAdan_room_15"
	include "HAKAdan_room_16"
	include "HAKAdan_room_17"
	include "HAKAdan_room_18"
	include "HAKAdan_room_19"
	include "HAKAdan_room_20"
	include "HAKAdan_room_21"
	include "HAKAdan_room_22"

	include "HAKAdanCH_scene"
	include "HAKAdanCH_room_0"
	include "HAKAdanCH_room_1"
	include "HAKAdanCH_room_2"
	include "HAKAdanCH_room_3"
	include "HAKAdanCH_room_4"
	include "HAKAdanCH_room_5"
	include "HAKAdanCH_room_6"

	include "ice_doukutu_scene"
	include "ice_doukutu_room_0"
	include "ice_doukutu_room_1"
	include "ice_doukutu_room_2"
	include "ice_doukutu_room_3"
	include "ice_doukutu_room_4"
	include "ice_doukutu_room_5"
	include "ice_doukutu_room_6"
	include "ice_doukutu_room_7"
	include "ice_doukutu_room_8"
	include "ice_doukutu_room_9"
	include "ice_doukutu_room_10"
	include "ice_doukutu_room_11"

	include "men_scene"
	include "men_room_0"
	include "men_room_1"
	include "men_room_2"
	include "men_room_3"
	include "men_room_4"
	include "men_room_5"
	include "men_room_6"
	include "men_room_7"
	include "men_room_8"
	include "men_room_9"
	include "men_room_10"

	include "ganontika_scene"
	include "ganontika_room_0"
	include "ganontika_room_1"
	include "ganontika_room_2"
	include "ganontika_room_3"
	include "ganontika_room_4"
	include "ganontika_room_5"
	include "ganontika_room_6"
	include "ganontika_room_7"
	include "ganontika_room_8"
	include "ganontika_room_9"
	include "ganontika_room_10"
	include "ganontika_room_11"
	include "ganontika_room_12"
	include "ganontika_room_13"
	include "ganontika_room_14"
	include "ganontika_room_15"
	include "ganontika_room_16"
	include "ganontika_room_17"
	include "ganontika_room_18"
	include "ganontika_room_19"

# 4327 "../spec.segment"


	include "market_day_scene"
	include "market_day_room_0"
	include "market_night_scene"
	include "market_night_room_0"










	include "kenjyanoma_scene"
	include "kenjyanoma_room_0"

	include "tokinoma_scene"
	include "tokinoma_room_0"
	include "tokinoma_room_1"






	include "link_home_scene"
	include "link_home_room_0"

	include "kokiri_shop_scene"
	include "kokiri_shop_room_0"

	include "kokiri_home_scene"
	include "kokiri_home_room_0"

	include "kakusiana_scene"
	include "kakusiana_room_0"
	include "kakusiana_room_1"
	include "kakusiana_room_2"
	include "kakusiana_room_3"
	include "kakusiana_room_4"
	include "kakusiana_room_5"
	include "kakusiana_room_6"
	include "kakusiana_room_7"
	include "kakusiana_room_8"
	include "kakusiana_room_9"
	include "kakusiana_room_10"
	include "kakusiana_room_11"
	include "kakusiana_room_12"
	include "kakusiana_room_13"

	include "entra_scene"
	include "entra_room_0"

	include "moribossroom_scene"
	include "moribossroom_room_0"
	include "moribossroom_room_1"

	include "syatekijyou_scene"
	include "syatekijyou_room_0"

	include "shop1_scene"
	include "shop1_room_0"

	include "hairal_niwa_scene"
	include "hairal_niwa_room_0"

	include "ganon_tou_scene"
	include "ganon_tou_room_0"






	include "market_alley_scene"
	include "market_alley_room_0"

	include "spot20_scene"
	include "spot20_room_0"

	include "market_ruins_scene"
	include "market_ruins_room_0"

	include "entra_n_scene"
	include "entra_n_room_0"

	include "enrui_scene"
	include "enrui_room_0"

	include "market_alley_n_scene"
	include "market_alley_n_room_0"

	include "hiral_demo_scene"
	include "hiral_demo_room_0"






	include "kokiri_home3_scene"
	include "kokiri_home3_room_0"

	include "malon_stable_scene"
	include "malon_stable_room_0"

	include "kakariko_scene"
	include "kakariko_room_0"

	include "bdan_boss_scene"
	include "bdan_boss_room_0"
	include "bdan_boss_room_1"

	include "FIRE_bs_scene"
	include "FIRE_bs_room_0"
	include "FIRE_bs_room_1"

	include "hut_scene"
	include "hut_room_0"

	include "daiyousei_izumi_scene"
	include "daiyousei_izumi_room_0"

	include "hakaana_scene"
	include "hakaana_room_0"

	include "yousei_izumi_tate_scene"
	include "yousei_izumi_tate_room_0"

	include "yousei_izumi_yoko_scene"
	include "yousei_izumi_yoko_room_0"

	include "golon_scene"
	include "golon_room_0"

	include "zoora_scene"
	include "zoora_room_0"

	include "drag_scene"
	include "drag_room_0"

	include "alley_shop_scene"
	include "alley_shop_room_0"

	include "night_shop_scene"
	include "night_shop_room_0"

	include "impa_scene"
	include "impa_room_0"

	include "labo_scene"
	include "labo_room_0"

	include "tent_scene"
	include "tent_room_0"

	include "nakaniwa_scene"
	include "nakaniwa_room_0"

	include "ddan_boss_scene"
	include "ddan_boss_room_0"
	include "ddan_boss_room_1"

	include "ydan_boss_scene"
	include "ydan_boss_room_0"
	include "ydan_boss_room_1"

	include "HAKAdan_bs_scene"
	include "HAKAdan_bs_room_0"
	include "HAKAdan_bs_room_1"

	include "MIZUsin_bs_scene"
	include "MIZUsin_bs_room_0"
	include "MIZUsin_bs_room_1"

	include "ganon_scene"
	include "ganon_room_0"
	include "ganon_room_1"
	include "ganon_room_2"
	include "ganon_room_3"
	include "ganon_room_4"
	include "ganon_room_5"
	include "ganon_room_6"
	include "ganon_room_7"
	include "ganon_room_8"
	include "ganon_room_9"

	include "ganon_boss_scene"
	include "ganon_boss_room_0"

	include "jyasinboss_scene"
	include "jyasinboss_room_0"
	include "jyasinboss_room_1"
	include "jyasinboss_room_2"
	include "jyasinboss_room_3"

	include "kokiri_home4_scene"
	include "kokiri_home4_room_0"

	include "kokiri_home5_scene"
	include "kokiri_home5_room_0"

	include "ganon_final_scene"
	include "ganon_final_room_0"

	include "kakariko3_scene"
	include "kakariko3_room_0"






	include "hakasitarelay_scene"
	include "hakasitarelay_room_0"
	include "hakasitarelay_room_1"
	include "hakasitarelay_room_2"
	include "hakasitarelay_room_3"
	include "hakasitarelay_room_4"
	include "hakasitarelay_room_5"
	include "hakasitarelay_room_6"

	include "shrine_scene"
	include "shrine_room_0"

	include "turibori_scene"
	include "turibori_room_0"

	include "shrine_n_scene"
	include "shrine_n_room_0"

	include "shrine_r_scene"
	include "shrine_r_room_0"

	include "hakaana2_scene"
	include "hakaana2_room_0"

	include "gerudoway_scene"
	include "gerudoway_room_0"
	include "gerudoway_room_1"
	include "gerudoway_room_2"
	include "gerudoway_room_3"
	include "gerudoway_room_4"
	include "gerudoway_room_5"

	include "hairal_niwa_n_scene"
	include "hairal_niwa_n_room_0"

	include "bowling_scene"
	include "bowling_room_0"

	include "hakaana_ouke_scene"
	include "hakaana_ouke_room_0"
	include "hakaana_ouke_room_1"
	include "hakaana_ouke_room_2"

	include "hylia_labo_scene"
	include "hylia_labo_room_0"

	include "souko_scene"
	include "souko_room_0"
	include "souko_room_1"
	include "souko_room_2"

	include "miharigoya_scene"
	include "miharigoya_room_0"

	include "mahouya_scene"
	include "mahouya_room_0"

	include "takaraya_scene"
	include "takaraya_room_0"
	include "takaraya_room_1"
	include "takaraya_room_2"
	include "takaraya_room_3"
	include "takaraya_room_4"
	include "takaraya_room_5"
	include "takaraya_room_6"

	include "ganon_sonogo_scene"
	include "ganon_sonogo_room_0"
	include "ganon_sonogo_room_1"
	include "ganon_sonogo_room_2"
	include "ganon_sonogo_room_3"
	include "ganon_sonogo_room_4"

	include "ganon_demo_scene"
	include "ganon_demo_room_0"






	include "face_shop_scene"
	include "face_shop_room_0"

	include "kinsuta_scene"
	include "kinsuta_room_0"

	include "ganontikasonogo_scene"
	include "ganontikasonogo_room_0"
	include "ganontikasonogo_room_1"




 











 
	include "bump_texture_static"

	include "anime_model_1_static"
	include "anime_model_2_static"
	include "anime_model_3_static"
	include "anime_model_4_static"
	include "anime_model_5_static"
	include "anime_model_6_static"
	include "anime_texture_1_static"
	include "anime_texture_2_static"
	include "anime_texture_3_static"
	include "anime_texture_4_static"
	include "anime_texture_5_static"
	include "anime_texture_6_static"

	include "softsprite_matrix_static"


# 1254 "../spec"








endwave
