#!/usr/bin/env python
import asyncio

@asyncio.coroutine
def process_one():
    print('Simple Event Loop Example')

def main():
    loop = asyncio.get_event_loop()
    loop.run_until_complete(process_one())
    loop.close()

if __name__ == '__main__':
    main()
