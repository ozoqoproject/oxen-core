import atexit
import sys

import pywallet3

from oxen_wallet_cli import version

class Context:
    """Holds global context related to the invocation of the tool"""

    def __init__(self):
        self.options = None
        self.logged_in = False
        self.configured = False
        self.wallet = None
        self.wallet_core_config = None
        self.keyring_manager = None

    def configure(self, options):
        self.options = options
        self.__dict__.update(options)
        self.wallet_core_config = pywallet3.WalletConfig()
        self.wallet_core_config.daemon.address = self.options["oxend_url"]
        self.keyring_manager = pywallet3.KeyringManager(self.options["network"])
        self.configured = True

sys.modules[__name__] = Context()
