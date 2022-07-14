"""
Name:        
    world_setup.py
Description:    
    Set up script for Gazebo-Scenic interface. 
    Inserts required plugins into world sdf file.
    Must ensure that world files have write permissions for this script to work. 
    Running this script multiple times on the same world file will cause duplicate plugin insertions. 
Requirements:
    - Pysdf
    - Write Permissions on world files
"""
from pysdf import SDF, Plugin
import argparse
parser = argparse.ArgumentParser()
parser.add_argument("path", help="absolute path to individual world file", type=str)
args = parser.parse_args
def main():
    parsed = SDF.from_file(args.path, remove_blank_text=True)
    parsed.worlds[0].add(Plugin(name="delete_models", filename="libdelete_models.so"))
    parsed.worlds[0].add(Plugin(name="model_stats", filename="libmodel_stats.so"))
    parsed.to_file(args.path, pretty_print=True)
    print("result: ")
    print(parsed.to_xml())
    return

