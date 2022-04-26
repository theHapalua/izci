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
  
  GD_page(Gtk::Orientation::VERTICAL),

  AP_expander(),
  AP_box(Gtk::Orientation::VERTICAL),
  GIMP_cbutton(),
  AI_expander(),
  AI_box(Gtk::Orientation::VERTICAL),
  Ink_cbutton(),

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
  Glib::ustring I_label_text("İzci Pardus işletim sistemi için başlangıç yazılımıdır. Linux türü işletim sistemlerini\nkullanmaya yeni başlayan biri daha önceden kullandığı programları\nçalıştıramaz. Alternatif bulması gerekir. Bu da acil işleri, projeleri olan bir kullanıcı için vakit kaybıdır.\nBu vakit kaybının yaşanmaması için izci sık kullanılan programların alternatiflerini bulur.\n\nEğer bulamazsanız en alt sekmedeki \"Wİne\" yazılımını indirin. Wine, exe dosyalarını\nlinux üzerinde çalıştırılmasını sağlar.");
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

  //Install
  Glib::ustring i_label("Install");
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
  if(this->LO_cbutton.get_active()){
    install_count++;
    install_list.push_back("Libre Office");
  }
  i_dialog.reset(new Gtk::MessageDialog(*this,"Installing Softwares",false,Gtk::MessageType::QUESTION,Gtk::ButtonsType::OK_CANCEL,true));
  i_dialog->set_secondary_text("The choosen softwares will be installed.");
  i_dialog->set_hide_on_close(true);
  i_dialog->signal_response().connect(sigc::mem_fun(*this,&AppWindow::on_install_dialog_response));
  i_dialog->show();
  
}

void AppWindow::on_install_dialog_response(int response_id){
  i_dialog->hide();
  std::cout << "Hello\n";
  switch(response_id){
    case Gtk::ResponseType::OK:{
      std::cout << "Installing.\n";
      break;
    }case Gtk::ResponseType::CANCEL:{
      std::cout << "Not installing.\n";
    }
  }
}
