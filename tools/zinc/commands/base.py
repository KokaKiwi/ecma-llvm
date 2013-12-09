
class BaseCommand(object):
    name = None
    help = None

    def configure(self, parser):
        pass

    def run(self, args):
        pass
