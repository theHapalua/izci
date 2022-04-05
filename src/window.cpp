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

  OP_page(Gtk::Orientation::HORIZONTAL),
  
  MO_expander(),
  MO_box(Gtk::Orientation::HORIZONTAL),
  LO_cbutton(),


  i_button()
{
  m_HeaderBar.set_show_title_buttons(true);
  set_titlebar(m_HeaderBar);
  set_title("Izci");
  set_default_size(1200, 700);
  
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

  // Page 1
  //Microsoft Office
  Glib::ustring OP_page_text("Ofis Programları");
  Glib::ustring MO_expander_text("Microsoft Office Alternatifleri");
  Glib::ustring LO_cbutton_text("Libre Office");
  LO_cbutton.set_label(LO_cbutton_text);
  LO_cbutton.set_margin_top(10);
  LO_cbutton.set_margin_start(30);
  MO_box.append(LO_cbutton);
  MO_expander.set_child(MO_box);
  MO_expander.set_label(MO_expander_text);
  MO_expander.set_expanded(false);
  MO_expander.set_margin_top(5);
  MO_expander.set_margin_start(20);
  OP_page.append(MO_expander);
  m_Stack.add(OP_page,OP_page_text,OP_page_text);
  
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

//Check Button Togglers

void AppWindow::install(){
  if(this->LO_cbutton.get_active()){
    std::cout << "Libre Office is Downloading.\n";
  }else{
    std::cout << "Libre Office is not Downloading.\n";
  }
}
