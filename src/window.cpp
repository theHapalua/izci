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
  button1(),
  button2(),
  i_button(),
  page1(Gtk::Orientation::HORIZONTAL),
  page2(Gtk::Orientation::HORIZONTAL)
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

  // Stack pages
  Glib::ustring b1_label("Button 1");
  Glib::ustring page1_text("Page 1");
  button1.set_margin(20);
  button1.set_margin_bottom(580);
  button1.set_label(b1_label);
  page1.append(button1);
  m_Stack.add(page1,page1_text,page1_text);

  Glib::ustring b2_label("Button 2");
  Glib::ustring page2_text("Page 2");
  button2.set_margin(20);
  button2.set_margin_bottom(580);
  button2.set_label(b2_label);
  page2.append(button2);
  m_Stack.add(page2,page2_text,page2_text);
  
  Glib::ustring i_label("Install");
  i_button.set_label(i_label);
  i_button.set_margin_start(540);
  i_button.set_margin_end(540);
  i_button.set_margin_top(15);
  i_button.set_margin_bottom(15);

  m_Box.append(i_button);
}

AppWindow::~AppWindow()
{
}

