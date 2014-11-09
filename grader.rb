require 'thor'
require 'shellwords'

class Grader < Thor
  Dir.glob(File.join(__dir__ + '/grader', "**", "*.rb")).each do |file|
    require file
  end
  
  desc "score MAZE", "score all submitted solvers for MAZE"
  def score (maze, options={})
    default_options = {}
    options = default_options.merge(options)
    
    if maze == 'all'
      puts "Grading all mazes..."
      clear_previous_results
      all_mazes.each do |maze|
        score maze, {keep_previous_results: true}
      end
    else
      puts "Grading #{maze}..."
      clear_previous_results unless options[:keep_previous_results]
      all_solvers.each do |solver|
        Runner.new(maze, solver).check
      end
    end
  end
  
  private
  
  def clear_previous_results
    `rm -rf results/*`
  end
    
  def all_mazes
    Dir.glob "mazes/*.maze"
  end
  
  def all_solvers
    Dir.glob "solvers/*.solver"
  end
end
  
Grader.start(ARGV)