#include <gtk/gtk.h>

#include "webrtc/base/ssladapter.h"
#include "flagdefs.h"

int main(int argc, char** argv) {
    gtk_init(&argc, &argv);

    rtc::FlagList::SetFlagsFromCommandLine(&argc, argv, true);
    if (FLAG_help) {
        rtc::FlagList::Print(NULL, false);
        return 0;
    }

    // Abort if the user specifies a port that is outside the allowed
    // range [1, 65535].
    if ((FLAG_port < 1) || (FLAG_port > 65535)) {
        printf("Error: %i is not a valid port.\n", FLAG_port);
        return -1;
    }

    rtc::InitializeSSL();

    rtc::CleanupSSL();
    return 0;
}