################ print_labels_sketch.py #################
#                                                       #
#    Script to obtain labels for DeepPen sketch         #
#    Part of train notebook                             #
#    By Antonio Priego Raya                             #
#    Code created for the DeepPen project:              #
#    https://github.com/AntonioPriego/DeepPen           #
#                                                       #
#########################################################

labels = sorted( labels_train.union(labels_val, labels_test) )

ordered_labels = "{"
for i in range(0,len(labels)):
  ordered_labels += "\"" + str(labels[i]) + "\", "
ordered_labels += "}"

print(ordered_labels)
