/* =================== deep_pen_model_data.h ===================
    Sketch for DeepPen
    By Antonio Priego Raya
    Code created for the DeepPen project:
    https://github.com/AntonioPriego/DeepPen
    
=========================================================== */

namespace {
  constexpr int num_labels = 26;
  const char *labels[num_labels] = {"0", "1", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "2", "20", "21", "22", "23", "24", "25", "3", "4", "5", "6", "7", "8", "9"};
  
  const char* foundLabel(int max_index)
  {
    if      (labels[max_index] == "0")
      return "a";
    else if (labels[max_index] == "1")
      return "b";
    else if (labels[max_index] == "2")
      return "c";
    else if (labels[max_index] == "3")
      return "d";
    else if (labels[max_index] == "4")
      return "e";
    else if (labels[max_index] == "5")
      return "f";
    else if (labels[max_index] == "6")
      return "g";
    else if (labels[max_index] == "7")
      return "h";
    else if (labels[max_index] == "8")
      return "i";
    else if (labels[max_index] == "9")
      return "j";
    else if (labels[max_index] == "10")
      return "k";
    else if (labels[max_index] == "11")
      return "l";
    else if (labels[max_index] == "12")
      return "m";
    else if (labels[max_index] == "13")
      return "n";
    else if (labels[max_index] == "14")
      return "o";
    else if (labels[max_index] == "15")
      return "p";
    else if (labels[max_index] == "16")
      return "q";
    else if (labels[max_index] == "17")
      return "r";
    else if (labels[max_index] == "18")
      return "s";
    else if (labels[max_index] == "19")
      return "t";
    else if (labels[max_index] == "20")
      return "u";
    else if (labels[max_index] == "21")
      return "v";
    else if (labels[max_index] == "22")
      return "w";
    else if (labels[max_index] == "23")
      return "x";
    else if (labels[max_index] == "24")
      return "y";
    else if (labels[max_index] == "25")
      return "z";
    else
      return "0";
  }

  char foundLabelBT(int max_index)
  {
    if      (labels[max_index] == "0")
      return 'a';
    else if (labels[max_index] == "1")
      return 'b';
    else if (labels[max_index] == "2")
      return 'c';
    else if (labels[max_index] == "3")
      return 'd';
    else if (labels[max_index] == "4")
      return 'e';
    else if (labels[max_index] == "5")
      return 'f';
    else if (labels[max_index] == "6")
       return 'g';
    else if (labels[max_index] == "7")
      return 'h';
    else if (labels[max_index] == "8")
      return 'i';
    else if (labels[max_index] == "9")
      return 'j';
    else if (labels[max_index] == "10")
      return 'k';
    else if (labels[max_index] == "11")
      return 'l';
    else if (labels[max_index] == "12")
      return 'm';
    else if (labels[max_index] == "13")
      return 'n';
    else if (labels[max_index] == "14")
      return 'o';
    else if (labels[max_index] == "15")
      return 'p';
    else if (labels[max_index] == "16")
      return '1';
    else if (labels[max_index] == "17")
      return 'r';
    else if (labels[max_index] == "18")
      return 's';
    else if (labels[max_index] == "19")
      return 't';
    else if (labels[max_index] == "20")
      return 'u';
    else if (labels[max_index] == "21")
      return 'v';
    else if (labels[max_index] == "22")
      return 'w';
    else if (labels[max_index] == "23")
      return 'x';
    else if (labels[max_index] == "24")
      return 'y';
    else if (labels[max_index] == "25")
      return 'z';
    else
      return '0';
  }
}
