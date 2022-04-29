#include "window.h"
#include <gtkmm.h>
#include <iostream>
#include <vector>


AppWindow::AppWindow()
:
  m_Box(Gtk::Orientation::VERTICAL),
  s_Box(Gtk::Orientation::HORIZONTAL),
  m_HeaderBar(),
  m_StackSidebar(),
  m_Separator(Gtk::Orientation::VERTICAL),
  m_Stack(),
  
  I_page(Gtk::Orientation::VERTICAL),
  I_label(),

  OP_page(Gtk::Orientation::VERTICAL),
  
  MO_expander(),
  MO_box(Gtk::Orientation::VERTICAL),
  LO_cbutton(),
  WPS_cbutton(),
  NP_expander(),
  NP_box(),
  AT_cbutton(),
  
  GD_page(Gtk::Orientation::VERTICAL),

  AP_expander(),
  AP_box(Gtk::Orientation::VERTICAL),
  GIMP_cbutton(),
  AI_expander(),
  AI_box(Gtk::Orientation::VERTICAL),
  Ink_cbutton(),

  D3_page(), 
  AC_expander(),
  AC_box(),
  Blend_cbutton(),

  AE_page(Gtk::Orientation::VERTICAL),
  AA_expander(),
  AA_box(),
  AU_cbutton(),
  FL_expander(),
  FL_box(),
  LMMS_cbutton(),

  AV_page(),
  AV_label(),

  VE_page(Gtk::Orientation::VERTICAL),
  PP_box(),
  PP_expander(),
  KD_cbutton(),
  AN_expander(),
  AN_box(Gtk::Orientation::VERTICAL),
  SYN_cbutton(),

  WS_page(Gtk::Orientation::VERTICAL),
  Wine_cbutton(),
  GB_cbutton(),

  i_button()
{
  m_HeaderBar.set_show_title_buttons(true);
  set_titlebar(m_HeaderBar);
  set_title("İzci");
  set_default_size(1200, 700);
  set_resizable(false);
  
  s_Box.set_margin_top(15);
  s_Box.set_margin_start(20);
  s_Box.set_margin_end(20);
  s_Box.set_margin_bottom(0);
  m_Box.append(s_Box);
  set_child(m_Box);
  

  s_Box.append(m_StackSidebar);
  s_Box.append(m_Separator);
  s_Box.append(m_Stack);
  m_Stack.set_expand();

  m_Stack.set_transition_type(Gtk::StackTransitionType::SLIDE_UP_DOWN);
  m_StackSidebar.set_stack(m_Stack);
  // Page 1 : Information
  Glib::ustring I_page_text("İzci nedir?");
  Glib::ustring I_label_text("İzci Pardus işletim sistemi için başlangıç yazılımıdır. Linux türü işletim sistemlerini\nkullanmaya yeni başlayan biri daha önceden kullandığı programları\nçalıştıramaz. Alternatif bulması gerekir. Bu da acil işleri, projeleri olan bir kullanıcı için vakit kaybıdır.\nBu vakit kaybının yaşanmaması için izci sık kullanılan programların alternatiflerini bulur.\n\nEğer bulamazsanız en alt sekmedeki \"Wİne\" yazılımını indirin. Wine, exe dosyalarını\nlinux üzerinde çalıştırılmasını sağlar. İsterseniz de \"Gnome Boxes\"ı indirip içine windows kurabilirsiniz. ");
  I_label.set_label(I_label_text);
  I_page.append(I_label);

  m_Stack.add(I_page, I_page_text, I_page_text);
  // Page 2 : Office Programs
  Glib::ustring OP_page_text("Ofis Programları");
  //Microsoft Office
  Glib::ustring MO_expander_text("Microsoft Office Alternatifleri");
 
  //Libre Office
  Glib::ustring LO_cbutton_text("Libre Office");
  LO_cbutton.set_label(LO_cbutton_text);
  LO_cbutton.set_margin_top(10);
  LO_cbutton.set_margin_start(30);

  //WPS Office
  Glib::ustring WPS_cbutton_text("WPS Office");
  WPS_cbutton.set_label(WPS_cbutton_text);
  WPS_cbutton.set_margin_top(5);
  WPS_cbutton.set_margin_start(30);
  
  MO_box.append(LO_cbutton);
  MO_box.append(WPS_cbutton);
  MO_expander.set_child(MO_box);
  MO_expander.set_label(MO_expander_text);
  MO_expander.set_expanded(false);
  MO_expander.set_margin_top(5);
  MO_expander.set_margin_start(20);
  OP_page.append(MO_expander);
  
  //Notepad++
  Glib::ustring NP_expander_text("Notepad++ Alternatifleri");

  //Atom Text Editor
  Glib::ustring AT_cbutton_text("Atom Text Editor");
  AT_cbutton.set_label(AT_cbutton_text);
  AT_cbutton.set_margin_top(10);
  AT_cbutton.set_margin_start(30);

  NP_box.append(AT_cbutton);
  NP_expander.set_child(NP_box);
  NP_expander.set_label(NP_expander_text);
  NP_expander.set_expanded(false);
  NP_expander.set_margin_top(20);
  NP_expander.set_margin_start(20);
  OP_page.append(NP_expander);
  m_Stack.add(OP_page,OP_page_text,OP_page_text);

  //Page 3 : Graphical Design
  Glib::ustring GD_page_text("Grafik Tasarım");
  
  //Adobe Photoshop
  Glib::ustring AP_expander_text("Adobe Photoshop Alternatifleri");
  Glib::ustring GIMP_cbutton_text("GIMP");
  GIMP_cbutton.set_label(GIMP_cbutton_text);
  GIMP_cbutton.set_margin_top(10);
  GIMP_cbutton.set_margin_start(30);
  AP_box.append(GIMP_cbutton);
  AP_expander.set_child(AP_box);
  AP_expander.set_label(AP_expander_text);
  AP_expander.set_expanded(false);
  AP_expander.set_margin_top(5);
  AP_expander.set_margin_start(20);
  GD_page.append(AP_expander);

  //Adobe Illustrator
  Glib::ustring AI_expander_text("Adobe Illustrator Alternatifleri");
  Glib::ustring Ink_cbutton_text("Inkscape");
  Ink_cbutton.set_label(Ink_cbutton_text);
  Ink_cbutton.set_margin_top(10);
  Ink_cbutton.set_margin_start(30);
  AI_box.append(Ink_cbutton);
  AI_expander.set_child(AI_box);
  AI_expander.set_label(AI_expander_text);
  AI_expander.set_expanded(false);
  AI_expander.set_margin_top(20);
  AI_expander.set_margin_start(20);
  GD_page.append(AI_expander);

  m_Stack.add(GD_page,GD_page_text,GD_page_text);

  //3D Design Page
  Glib::ustring D3_page_text("3D Tasarım");
  //AutoCAD
  Glib::ustring AC_expander_text("AutoCAD Alternatifleri");
  Glib::ustring Blend_cbutton_text("Blender");
  Blend_cbutton.set_label(Blend_cbutton_text);
  Blend_cbutton.set_margin_top(10);
  Blend_cbutton.set_margin_start(30);
  AC_box.append(Blend_cbutton);
  AC_expander.set_child(AC_box);
  AC_expander.set_label(AC_expander_text);
  AC_expander.set_expanded(false);
  AC_expander.set_margin_top(20);
  AC_expander.set_margin_start(20);
  D3_page.append(AC_expander);

  m_Stack.add(D3_page,D3_page_text,D3_page_text);

  //Audio Editing Page
  Glib::ustring AE_page_text("Ses Düzenleme");
  //Adobe Audition
  Glib::ustring AA_expander_text("Adobe Audition");
  Glib::ustring AU_cbutton_text("Audacity");
  AU_cbutton.set_label(AU_cbutton_text);
  AU_cbutton.set_margin_top(10);
  AU_cbutton.set_margin_start(30);
  AA_box.append(AU_cbutton);
  AA_expander.set_child(AA_box);
  AA_expander.set_label(AA_expander_text);
  AA_expander.set_margin_top(20);
  AA_expander.set_margin_start(20);
  AE_page.append(AA_expander);
  
  //FL Studio
  Glib::ustring FL_expander_text("FL Studio");
  Glib::ustring LMMS_cbutton_text("LMMS");
  LMMS_cbutton.set_label(LMMS_cbutton_text);
  LMMS_cbutton.set_margin_top(10);
  LMMS_cbutton.set_margin_start(30);
  FL_box.append(LMMS_cbutton);
  FL_expander.set_child(FL_box);
  FL_expander.set_label(FL_expander_text);
  FL_expander.set_margin_top(20);
  FL_expander.set_margin_start(20);
  AE_page.append(FL_expander);

  m_Stack.add(AE_page,AE_page_text,AE_page_text);

  //Antivirus Page
  Glib::ustring AV_page_text("Antivirüs");
  Glib::ustring AV_label_text("Pardus, linux tabanlı bir işletim sistemidir. Linux\ntabanlı işletim sistemleri antivirüslere ihtiyaç duymaz. :)");
  AV_label.set_label(AV_label_text);
  AV_label.set_margin_start(300);
  AV_page.append(AV_label);

  m_Stack.add(AV_page,AV_page_text,AV_page_text);
    
  //Video Editing
  Glib::ustring VE_page_text("Video Düzenleme");

  //Adobe Premiere Pro
  Glib::ustring PP_expander_text("Adobe Premiere Pro Alternatifleri");
  Glib::ustring KD_cbutton_text("Kdenlive");
  KD_cbutton.set_label(KD_cbutton_text);
  KD_cbutton.set_margin_top(10);
  KD_cbutton.set_margin_start(30);
  PP_box.append(KD_cbutton);
  PP_expander.set_child(PP_box);
  PP_expander.set_label(PP_expander_text);
  PP_expander.set_margin_top(20);
  PP_expander.set_margin_start(20);
  VE_page.append(PP_expander);
  
  //Adobe Animate
  Glib::ustring AN_expander_text("Adobe Animate Alternatifleri");
  Glib::ustring SYN_cbutton_text("Synfig Studio");
  SYN_cbutton.set_label(SYN_cbutton_text);
  SYN_cbutton.set_margin_top(10);
  SYN_cbutton.set_margin_start(30);
  AN_box.append(SYN_cbutton);
  AN_expander.set_child(AN_box);
  AN_expander.set_label(AN_expander_text);
  AN_expander.set_margin_top(20);
  AN_expander.set_margin_start(20);
  AN_expander.set_expanded(false);
  VE_page.append(AN_expander);
  
  m_Stack.add(VE_page,VE_page_text,VE_page_text);
  
  //Windows Softwares Page
  Glib::ustring WS_page_text("Windows Yazılımları");
  Glib::ustring Wine_cbutton_text("Wine");
  Glib::ustring GB_cbutton_text("Gnome Boxes");
  Wine_cbutton.set_label(Wine_cbutton_text);
  Wine_cbutton.set_margin_top(10);
  Wine_cbutton.set_margin_start(30);
  WS_page.append(Wine_cbutton);
  GB_cbutton.set_label(GB_cbutton_text);
  GB_cbutton.set_margin_top(10);
  GB_cbutton.set_margin_start(30);
  WS_page.append(GB_cbutton);

  m_Stack.add(WS_page,WS_page_text,WS_page_text);

  //Install
  Glib::ustring i_label("İndir");
  i_button.set_label(i_label);
  i_button.set_margin_start(540);
  i_button.set_margin_end(540);
  i_button.set_margin_top(15);
  i_button.set_margin_bottom(15);
  i_button.signal_clicked().connect(sigc::mem_fun(*this, &AppWindow::install));

  m_Box.append(i_button);
}

AppWindow::~AppWindow(){}

void AppWindow::install(){
  int install_count = 0;
  std::vector<char*> install_list;
  /*if(this->LO_cbutton.get_active()){
    install_count++;
    install_list.push_back("Libre Office");
  }*/
  i_dialog.reset(new Gtk::MessageDialog(*this,"İndiriliyor",false,Gtk::MessageType::QUESTION,Gtk::ButtonsType::OK_CANCEL,true));
  i_dialog->set_secondary_text("Seçtiğiniz yazılımlar indirilecektir, \nonaylıyor musunuz?");
  i_dialog->set_hide_on_close(true);
  i_dialog->signal_response().connect(sigc::mem_fun(*this,&AppWindow::on_install_dialog_response));
  i_dialog->show();
  
}

void AppWindow::on_install_dialog_response(int response_id){
  i_dialog->hide();
  switch(response_id){
    case Gtk::ResponseType::OK:{
      std::cout << "Installing.\n";
      break;
    }case Gtk::ResponseType::CANCEL:{
      std::cout << "Not installing.\n";
    }
  }
}
