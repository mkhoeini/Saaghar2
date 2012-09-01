##############################################
# The 'pQjWidgets' a set of Qt widgets!      #
# The 'pQjWidgets' comes from PoJh QWidgets  #
#                                            #
# Copy Right by:                             #
# S. Razi Alavizadeh, Pozh,2011              #
# email: s.r.alavizadeh@gmail.com            #
#                                            #
# The 'pQjWidgets' is dual licensed:         #
# GPL licence for Open Source developments,  #
# and Commerical licence for other users.    #
# to purchase a commerical licence           #
# contact: <email: s.r.alavizadeh@gmail.com> #
##############################################

pQjWidgetsVersion = 0.1.1-1

!build_pass:message("Thanks for using pQjWidgets. pQjWidgets version: $${pQjWidgetsVersion}")

include(QMultiSelectWidget.pri)
include(QSearchLineEdit.pri)
include(QTextBrowserDialog.pri)
include(QExtendedSplashScreen.pri)

