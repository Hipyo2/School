defmodule InClass.Company.Task do
  use Ecto.Schema
  import Ecto.Changeset

  alias InClass.Company.{Generalarea, Developer, Assignment}
  schema "tasks" do
    field :description, :string
    field :name, :string
    belongs_to(:generalarea, Generalarea)
    has_many(:assignments, Assignment)
    many_to_many(:developers, Developer, join_through: Assignment)
    timestamps()
  end

  @doc false
  def changeset(task, attrs) do
    task
    |> cast(attrs, [:name, :description, :generalarea_id])
    |> validate_required([:name, :description, :generalarea_id])
  end
end
